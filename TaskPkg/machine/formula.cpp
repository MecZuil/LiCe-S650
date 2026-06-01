#include "formula.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

formula::formula(void)
{
}
formula::~formula(void)
{
}


/********************************************************************
 * @ description : 运算符优先级比较
 * @ param - a   : 运算符 1
 * @ param - b   : 运算符 2
 * @ return      : true->a>b  false->a<b
 ********************************************************************/
bool formula::cmpPRI( unsigned char a, unsigned char b)
{
    int priList[200];
    priList['\0']= 16;
    priList['('] = 1;
    priList[')'] = 1;
    priList['*'] = 3;
    priList['/'] = 3;
    priList['+'] = 4;
    priList['-'] = 4;
    priList['&'] = 11;
    priList['|'] = 12;
    priList['<'] = 9;
    priList['>'] = 9;
    priList['$'] = 9;
    priList['#'] = 9;
    priList['%'] = 2;
    if( priList[ a ] < priList[ b ] ) return true;
    else return false;
}

/********************************************************************
 * @ description   : 公式到后缀式转换
 * @ param - expr  : 原始公式
 * @ param - rExpr : 栈容器
 * @ return        : null
 ********************************************************************/
void formula::E2Postfix(string expr, stack<string> &rExpr)
{
    //string expr=Expr;
    //stack<string> rExpr;
    stack<char> opS;                        //保存运算符 优先级越高的运算符越接近栈顶
    opS.push(0);                            //压栈

    int eLen(expr.size());                  //字符串长度

    bool isDigit(false);                    //类型是否为数字
    string dTmp;
    string oTmp;

    /* 遍历字符串 */
    for( int i=0; i < eLen; i++){
        /* 数字、'.'、'^'类型判断 */
        if(isdigit(expr[i]) || expr[i] == '.'|| expr[i] == '^') isDigit = true;
        else isDigit = false;
        /* 数字 */
        if(isDigit) {
            /* '^' */
            if(expr[i] == '^')
                dTmp += "-";
            /* 数字、'.' */
            else
                dTmp += expr[i];
        /* 非数字 */
        } else {
            if( !dTmp.empty() )
                rExpr.push(dTmp);           //非空时压栈
            dTmp = "";
            /* 右括号 */
            if(expr[i] == ')'){
                while(opS.top() != '(') {
                    oTmp.clear();
                    oTmp += (char)opS.top();
                    rExpr.push(oTmp);
                    opS.pop();
                }
                opS.pop();
            /* expr[i]优先级大于opS.top() / 左括号 */
            } else if ( cmpPRI(expr[i], opS.top()) || opS.top() == '(') {
                opS.push(expr[i]);          //压栈
            /* 其他运算符 */
            } else {
                oTmp.clear();
                oTmp += (char)opS.top();
                rExpr.push(oTmp);
                opS.pop();
                if( isdigit(expr[i+1]) || expr[i] == '.' ){

                } else{
                    if( opS.top()!='(') {
                        oTmp.clear();
                        oTmp += (char)opS.top();
                        if( oTmp.at(0)==0 ) {
                        }
                        else{
                            rExpr.push(oTmp);
                            opS.pop();
                        }
                    }
                }
                opS.push(expr[i]);
            }
        }
    }

    if(!dTmp.empty()) rExpr.push(dTmp);
    while(!opS.empty()){
        oTmp.clear();
        oTmp += opS.top();
        rExpr.push(oTmp);
        opS.pop();
    }
    rExpr.pop();
}


/********************************************************************
 * @ description    : 后缀表达式计算
 * @ param - rExper : 栈容器
 * @ return         : double
 ********************************************************************/
double formula::run_result( stack<string> rExper )
{
    //int getop(char s);
    string temp;

    /* 栈容器大小判断 */
    int mq= rExper.size();
    if ( mq <= 0 ) { return 0; }
    if( mq == 1 ){
        return atof( rExper.top().c_str() );
    }

    /* 遍历栈容器，提取后缀表达式 */
    for( int i=0; i < mq; i++)
    {
        if( i == 0 ) {
            temp = rExper.top();
        } else {
            temp.insert(0,rExper.top()+" ");
        }
        rExper.pop();
    }

    //temp.clear();
    //temp  ="3 1 * 2 + ";
    int type;
    double op2;
    char s[ MAXOP ] = {'@'};
    for ( int i = 0; i< MAXOP; i++ )
    {
        s[i]='@';
    }
    for( unsigned int i=0; i<temp.size(); i++)
    {
        s[i]=temp.at(i);
    }
    cout << "#### [formula] [run_result] : temp = " << temp << "; s = " << s << endl;

    int ap=0;

    /* 获取第一个元素 */
    sp = 0;
    string ca;
    ca.clear();
    while( s[ap] != ' ')
    {
        ca+=s[ap];
        ap++;
    }
    ap++;
    //ca= s[sp];
    double m;

    /* 遍历ca */
    while( ( type = getop( ca ) ) != EOF )
    {
        cout << "#### [formula] [run_result] : ca = " << ca << endl;
        switch(type)
        {
        /* 数字 */
        case 0:
            push( atof( ca.c_str() ) );             /* string转换为double */
            break;
        /* + */
        case 1:
            push( pop() + pop() );
            break;
        /* * */
        case 3:
            push( pop() * pop() );
            break;
        /* - */
        case 2:
            op2 = pop();
            push( pop() - op2 );
            break;
        /* / */
        case 4:
            op2 = pop();
            if( op2 != 0.0 )
                push( pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        /* & */
        case 5:
            op2 = pop();
            push( pop() && op2 );
            break;
        /* > */
        case 6:
            op2 = pop();
            if( pop() > op2 )
                m = 1;
            else{
                m = 0;
            }
            push( m );
            break;
        /* < */
        case 7:
            op2 = pop();
            if( pop() < op2 ) {
                m=1;
            } else {
                m=0;
            }
            push( m );
            break;
        /* = */
        case 8:
            op2 = pop();
            if( pop() == op2 ) {
                m = 1;
            } else {
                m = 0;
            }
            push(m);
            break;
        /* | */
        case 9:
            op2 = pop();
            push(pop() || op2 );
            break;
        /* <= */
        case 10:
            op2 = pop();
            if( pop() <= op2 ){
                m = 1;
            } else {
                m = 0;
            }
            push( m );
            break;
        /* >= */
        case 11:
            op2 = pop();
            if( pop() >= op2 ){
                m = 1;
            }else{
                m = 0;
            }
            push(m);
            break;
        /* % */
        case 14:
            push(pop()/100);
            break;
        case 100:
            return pop();
            break;
        default:
            break;
        }

        /* 获取下一个 */
        ca.clear();
        while( s[ap] != ' ' && s[ap] != '@')
        {
            ca+=s[ap];
            ap++;
        }
        ap++;
    }

    return val[0];
}


/****************************************************************************
 * @ description : 获取目标字符串首字符类型
 * @ param - s   : 目标字符串
 * @ return      : 运算符类型
 ****************************************************************************/
int formula::getop(string s)
{
    if(s.empty())
        return EOF;

    if(s.size() > 1 ){return 0;}
    switch(s.at(0))
    {
    case '+':               // +
        return 1;
        break;
    case '-':               // -
        return 2;
        break;
    case '*':               // *
        return 3;
        break;
    case '/':               // /
        return 4;
        break;
    case '&':               // &
        return 5;
        break;
    case '>':               // >
        return 6;
        break;
    case '<':               // <
        return 7;
        break;
    case  '=':              // =
        return 8;
        break;
    case  '|':              // |
        return 9;
        break;
    case '#':               // <=
        return 10;
        break;
    case '$':               // >=
        return 11;
        break;
    case ' ':
        return 12;
        break;
    case '@':
        return 13;
        break;
    case '%':
        return 14;
        break;
    default:
        break;
    }
    return 0;
}


/********************************************************************
 * @ description : 压栈，内容添加至val数组
 * @ param - f   : 需要压入的内容
 * @ return      : null
 ********************************************************************/
void formula::push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    //else

    //printf("error: stack full, can't push %g\n", f);
}


/********************************************************************
 * @ description : 返回栈顶元素内容
 * @ param       : null
 * @ return      : fouble
 ********************************************************************/
double formula::pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        return 0.0;
    }
}

/********************************************************************
 * @ description : 清空栈容器
 * @ param       : null
 * @ return      : null
 ********************************************************************/
void formula::clean_stack()
{
    for( int i=0; i<MAXOP; i++ ) {
        val[i]=double(0);
    }
    sp=0;
}

/********************************************************************
 * @ description  : 公式计算
 * @ param - temp : 公式
 * @ return       : double
 ********************************************************************/
double formula::return_run_data(string temp)
{
    //清空栈容器
    clean_stack();
    //int run_result( stack<string> rExper );
    stack<string> rExpr;
    string expr;
    expr=temp;

    /* 后缀表达式转换 */
    E2Postfix(expr,rExpr);

    /* 计算 */
    double reid = run_result(rExpr);
    return reid;
}





















