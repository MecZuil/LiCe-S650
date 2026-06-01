#ifndef MODULE_H
#define MODULE_H

#include <QString>
class CModule
{
public:
    CModule();

    static bool copy_dir( const QString& s_src_path, const QString& s_dst_path, bool b_cover_file_exist );
    static bool remove_dir( const QString& s_dir_path );
};

#endif // MODULE_H
