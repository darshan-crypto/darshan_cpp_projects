#include <string>
typedef std::string string;
class Payload
{
public:
    Payload(string);
    void getPayload(string *);
    string getHeader() { return data; }

private:
    string data;
    string payload;
    void process();
    int start;
};
Payload::Payload(string s)
{
    data = s;
    process();
}
void Payload::getPayload(string *output)
{

    *output = payload;
}
void Payload::process()
{
    for (int i = 0; i < data.length(); i++)
    {
        if (data.at(i) == '\r')
        {
            if (data.at(i + 1) == '\n')

            {
                if (data.at(i + 2) == '\r')
                {
                    if (data.at(i + 3) == '\n')
                    {
                        start = i + 4;
                    }
                }
            }
        }
    }

    for (int i = start; i < data.length(); i++)
    {
        payload.append(1, data.at(i));
    }
}