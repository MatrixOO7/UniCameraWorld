#include "unibaseinfo.h"

UniBaseInfo::UniBaseInfo( QObject *parent ) {
    LoadDefault();
}

void UniBaseInfo::LoadDefault() {
    m_name = "default";
    m_version = "1.0.0";
    m_description = "Default fault theme load.";
    m_author = "KrejVers";
}

bool UniBaseInfo::Load(const QJsonDocument &doc) {

    return false;
}

void UniBaseInfo::setName( const QString value ) {
    if ( m_name != value ) {
        m_name = value;
        emit nameChanged();
    }
}

void UniBaseInfo::setVersion( const QString value ) {
    if ( m_version != value ) {
        m_version = value;
        emit versionChanged();
    }
}

void UniBaseInfo::setDescription( const QString value ) {
    if ( m_description != value ) {
        m_description = value;
        emit descriptionChanged();
    }
}

void UniBaseInfo::setAuthor( const QString value ) {
    if ( m_author != value ) {
        m_author = value;
        emit authorChanged();
    }
}
