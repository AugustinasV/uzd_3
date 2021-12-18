#include "v3class.h"

using namespace std;

Student::Student() {
    vardas_ = "";
    pavarde_ = "";
    galutinis_ = 0;
    galutinis_paz_ = 0;
    egz_paz_ = 0;
    nd_paz_.reserve(columncount - 3);
    wordread_.reserve(columncount);
}

void Student::setwordread(vector <string> v) {
    wordread_ = v;
}

Student::Student(const Student& df) {
    vardas_ = df.vardas_;
    pavarde_ = df.pavarde_;
    galutinis_paz_ = df.galutinis_paz_;
    egz_paz_ = df.egz_paz_;
    galutinis_ = df.galutinis_;

    for (int i = 0; i != nd_paz_.size(); i++) {
        nd_paz_[i] = df.nd_paz_[i];
    }
}

Student& Student::operator=(const Student& st) {
    if (&st == this) {
        return *this;
    }
    vardas_ = st.vardas_;
    pavarde_ = st.pavarde_;
    galutinis_paz_ = st.galutinis_paz_;
    egz_paz_ = st.egz_paz_;
    galutinis_ = st.galutinis_;

    for (int i = 0; i != nd_paz_.size(); i++) {
        nd_paz_[i] = st.nd_paz_[i];
    }
    return *this;
}

int main() {

    outputPath();

    lineread.reserve(filesize);

    timer a;
    fileGenerator();
    idk(a, "generation");

    readLine();

    timer c;

    vector <Student> grupedu;
    vector <Student> grupedu_v;


    grupedu.resize(linecount);

    for (int x = 0; x < linecount; x++)             /// vector handle   
    {
        readStr(lineread[x]);
        grupedu[x].setwordread(temp);
        temp.clear();

        try
        {
            grupedu[x].assign();
        }
        catch (int qwe)
        {
            cout << "ERROR: corrupt data on line " << (x + 1) << endl;
            errorcount++;
        }
        catch (char const* zxc)
        {
            cout << "ERROR: bad int on line " << (x + 1) << endl;
            errorcount++;
        }
    }

    idk(c, "handling");

    timer b;

    sortWrite(grupedu, grupedu_v);

    grupedu.erase(remove_if(grupedu.begin(), grupedu.end(), [](const Student& c) {return c.galutinis_paz() < 5; }), grupedu.end());

    idk(b, "sort+writing");

    cout << std::to_string(filesize) + ".txt total: " << vectortotaltime << "s" << endl;


}