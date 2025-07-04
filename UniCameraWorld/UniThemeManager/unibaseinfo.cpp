#include "unibaseinfo.h"

UniBaseInfo::UniBaseInfo() {
    LoadDefault();
}

void UniBaseInfo::LoadDefault() {
    name = "default";
    version = "1.0.0";
    description = "Default fault theme load.";
    author = "KrejVers";
}

bool UniBaseInfo::Load(QString path) {

    return false;
}

void UniBaseInfo::setName( QString value ) {
    name = value;
}

void UniBaseInfo::setVersion( QString value ) {
    version = value;
}

void UniBaseInfo::setDescription( QString value ) {
    description = value;
}

void UniBaseInfo::setAuthor( QString value ) {
    author = value;
}
