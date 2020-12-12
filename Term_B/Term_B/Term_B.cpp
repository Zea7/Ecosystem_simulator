#pragma warning(disable: 4996)

#include <iostream>
#define MAXNAME 8196

using namespace std;

typedef struct ECOSYSTEM {
    double place_c;                                    //생태계 터전의 크기(Consumer)
    double place_p;                                    //생태계 터전의 크기(Productor)
    double energy;                                     //생태계 총 에너지 양
    double production;                                 //Productor가 제공하는 자원
    double food;                                       //Consumor가 제공하는 자원
    double leftover;                                   //생명체들이 죽고 나서 남는 찌꺼기
}Ecosystem;

Ecosystem eco;

class Organism {
private:        
    char* name;                                        //생물체의 이름
    double size;                                       //생물체의 크기
    double time_to_reproduction;                       //생식 사이의 소요기간(성체일 때만 함)
    int number_of_children;                            //자식의 수
    double baby;                                       //유체로 머무르는 시간
    double youth;                                      //유체와 성체 사이에서 머무르는 시간
    double adult;                                      //성체로 머무르는 시간
    double lifespan;                                   //평균 수명
    double age=0;                                      //현재 나이
public:
    Organism();
    void change_name(char* n) { this->name = n; };
    void change_size(double size) { this->size = size; };
    void change_repro(double repro) { this->time_to_reproduction = repro; };
    void change_num_child(int ch) { this->number_of_children = ch; };
    void change_baby(double b) { this->baby = b; };
    void change_youth(double y) { this->youth = y; };
    void change_adult(double a) { this->adult = a; };
};
Organism::Organism() {
    char n[MAXNAME];
    cout << "생명체의 이름은?" << endl;
    cin >> n;
    this->name = n;
    cout << "생명체의 크기는?" << endl;
    cin >> this->size;
    cout << "생명체가 다음 세대를 만들때까지 소요 되는 시간은?" << endl;
    cin >> this->time_to_reproduction;
    cout << "한 번에 낳는 자식의 수는?" << endl;
    cin >> this->number_of_children;
    cout << "유체로 머무르는 시간은?" << endl;
    cin >> this->baby;
    cout << "유체와 성체 사이에 소요되는 시간은?" << endl;
    cin >> this->youth;
    cout << "성체로 머무르는 시간은?" << endl;
    cin >> this->adult;
    this->lifespan = this->baby + this->youth + this->adult;
}


class Productor : public Organism {
private:
    double product;                     //해당 productor가 ecosystem에 제공할 자원의 양
    double energy;                      //해당 productor가 살아가는 동안 연당 소비하는 자원의 양
public:
    void change_product(double p) { this->product = p; };
    void change_energy(double e) { this->energy = e; };
};

class Consumer : public Organism {
private:
    double food;                        //해당 consumer가 죽어서 ecosystem에 제공할 자원의 양              
    double resource;                    //해당 consumer가 살아가는 동안 연당 소비하는 자원의 양
public:
    void change_food(double f) { this->food = f; };
    void change_resource(double r) { this->resource = r; };
};

class Decomposer : public Organism {
public:

};

int main()
{
    cout << "### ecosystem simulation ###" << endl;
    cout << "프로그램 내에서 시간의 단위는 전부 연(year)단위 입니다." << endl;
    Organism o;
    
}

