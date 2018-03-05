#ifndef SERVICE_LEVELDB_H
#define SERVICE_LEVELDB_H

#include "dbwrapper.h"

#include <map>
#include <string>
#include <utility>
#include <vector>

/** Access to a given service's database (service/[name]/)
* Use leveldb since we already implement it for txindex and blockindexes.
* no need to find a new db when leveldb already works
*/
class CServiceDB : public CDBWrapper
{
public:
    CServiceDB(std::string name, size_t nCacheSize, bool fMemory = false, bool fWipe = false);
private:
    CServiceDB(const CServiceDB&);
    void operator=(const CServiceDB&);
public:
    bool WriteBatchSync();

    bool WriteFlag(const char &SERVICE_FLAG, const std::string &name, bool fValue);
    bool ReadFlag(const char &SERVICE_FLAG, const std::string &name, bool &fValue);
    bool EraseFlag(const char &SERVICE_FLAG, const std::string &name);

    bool WriteEntry(const char &SERVICE_FLAG, const std::string &name, void *value);
    bool ReadEntry(const char &SERVICE_FLAG, const std::string &name, void *value);
    bool EraseEntry(const char &SERVICE_FLAG, const std::string &name);
};

#endif // SERVICE_LEVELDB_H