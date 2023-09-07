#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class UserInfo;
class InvalidHostError;
class EscapeError;
class Values;


const string upperhex = "0123456789ABCDEF";
bool ishex(char c);
char unhex(char c);

enum encoding {
    encodePath = 1,
    encodePathSegment,
    encodeHost,
    encodeZone,
    encodeUserPassword,
    encodeQueryComponent,
    encodeFragment,
};

class Error 
{
    public:
        Error();
        ~Error();

        const string& Unwrap();
        const string& ErrorStr();
        virtual bool Timeout();
        virtual bool Temporary();
    public:
        string Err;
        string Op;
        string Url;
};

class URL 
{
    public:
        string Scheme;     
        string Opaque;         // encoded opaque data
        UserInfo* User;        // username and password information
        string Host;           // host or host:port
        string Path;           // path (relative paths may omit leading slash)
        string RawPath;        // encoded path hint (see EscapedPath method)
        bool ForceQuery;       // append a query ('?') even if RawQuery is empty
        string RawQuery;       // encoded query values, without '?'
        string Fragment;       // fragment for references, without '#'
};

class UserInfo
{
    public:
        string username;    
        string password;    
        bool passwordSet; 

};

class Values
{
    public:
        const string& Get(const string& key);
        void Set(const string& key, const string& value);
        void Add(const string& key, const string& value);
        bool Del(const string& key);
    private:
        unordered_map<string, vector<string> > m_values;
};
