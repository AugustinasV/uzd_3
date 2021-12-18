#include "v3functions.h"

class person {
public:
    virtual void assign() = 0;
};

class Student : public person
{
private:

    string vardas_, pavarde_;
    float galutinis_paz_, galutinis_;
    int egz_paz_;
    vector <int> nd_paz_;
    vector <string> wordread_;

public:

    void calcGalutinis() {
        galutinis_paz_ = (((galutinis_) / nd_paz_.size()) * 0.4 + egz_paz_ * 0.6);
    }

    void assign()
    {
        if (wordread_.size() == columncount)
        {
            for (int x = 2; x < wordread_.size() - 1; x++)
            {
                nd_paz_.push_back(std::stoi(wordread_[x]));
                galutinis_ += std::stoi(wordread_[x]);
            }
            vardas_ = wordread_[0];
            pavarde_ = wordread_[1];
            egz_paz_ = std::stoi(wordread_[wordread_.size() - 1]);
            galutinis_paz_ = (((galutinis_) / nd_paz_.size()) * 0.4 + egz_paz_ * 0.6);
        }
        else {
            throw 402;
        }
    }

    Student(const Student& df);

    ~Student() {}

    Student& operator=(const Student& st);

    void setwordread(vector <string> v);

    Student();

    string vardas() const { return vardas_; }
    string pavarde() const { return pavarde_; }
    float galutinis_paz() const { return galutinis_paz_; }
    float galutinis() const { return galutinis_; }
    int egz_paz() const { return egz_paz_; }
    vector <int> nd_paz() const { return nd_paz_; }
    vector <string> wordread() const { return wordread_; }
};

void sortWrite(vector <Student> a, vector <Student> a_v) {

    std::vector<Student>::iterator lp;
    ofstream file33(path + std::to_string(filesize) + " maziau 5.txt");
    ofstream file44(path + std::to_string(filesize) + " daugiau 5.txt");

    lp = a.begin();

    int ii = 0;
    for (lp = a.begin(); lp != a.end();)
    {
        if (lp->galutinis_paz() < 5)
        {
            a_v.push_back(*lp);
            file33 << lineread[ii] << endl;
        }
        else
        {
            file44 << lineread[ii] << endl;
        }
        lp++;
        ii++;
    }
    file33.close();
    file44.close();
}