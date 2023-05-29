#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Reference {
public:
    std::string source;
    std::string language;

};

int main() {
    setlocale(LC_ALL, "RUS");
    std::vector<Reference> references = {
        {"Moore, J.L., Dickson - Deane, C.,& Galyen, K. (2011).e - Learning, online learning,and distance learning environments : Are they the same ? .The Internet and Higher Education, 14(2), 129 - 135.","Eng"},
        {"Cinquin, P.A., Guitton, P.,& Sauzéon, H. (2019).Online e - learning and cognitive disabilities : A systematic review.Computers & Education, 130, 152 - 167.","Eng"},
        {"Maslow, A.H. (1966).The psychology of science a reconnaissance.","Eng"},
        {"Harvey, O.J., Hunt, D.E.,& Schroder, H.M. (1961).Conceptual systemsand personality organization.","Eng"},
        {"Wood, J.,& BacKWell, J. (2012).harnessing hidden knowledge for paradigm change.Journal of Writing in Creative Practice, 5(3), 477 - 497.","Eng"},
        {"García, M.L. (2008).Closed Groups, Hidden Knowledge.An Anthropological Perspective.","Eng"},
        {"Madsen, E.S., Riis, J.O.,& Waehrens, B.V. (2008).The knowledge dimension of manufacturing transfers.Strategic Outsourcing : An International Journal.","Eng"},
        {"Fershtman, C.,& Gandal, N. (2011).Directand indirect knowledge spillovers : the “social network” of open‐source projects.The RAND Journal of Economics, 42(1), 70 - 91.","Eng"},
        {"Маслоу А.Г.Мотивация и личность.М., 2000. 225 с.","Rus"},
        {"Toivonen, S., Lenzini, G.,& Uusitalo, I. (2006, November).Context - aware trustworthiness evaluation with indirect knowledge.In Proc.of the 2nd International Semantic Web Policy Workshop(SWPW).","Eng"},
        {"Eraut, M. (2000).Non - formal learning and tacit knowledge in professional work.British journal of educational psychology, 70(1), 113 - 136.","Eng"},
        {"Mortensen, M.,& Neeley, T.B. (2012).Reflected knowledgeand trust in global collaboration.Management Science, 58(12), 2207 - 2224.","Eng"},
        {"Ушинский, К.Д.Педагогика.Избранные работы, М.Юрайт, 2017, 284 с.","Rus"},
        {"Wright, J.C.,& Mischel, W. (1988).Conditional hedgesand the intuitive psychology of traits.Journal of personalityand social psychology, 55(3), 454.","Eng"},
    };




    // Сортировка списка литературы по алфавиту сначала по языку, затем по названию
    std::sort(
        references.begin(), references.end(),
        [](Reference& r1, Reference& r2) {
            if (r1.language == r2.language) {
                return r1.source < r2.source;
            }
            return r1.language == "Rus" && r2.language == "Eng";
        });

   
 
    bool withNumbers = true;  // выводить ли номера источников

    // Вывод списка литературы
    std::cout << "Литература с номерами:\n";
    int i = 1;
    for (const Reference& r : references) {
        std::string s = withNumbers ? std::to_string(i) + ". " : "";
        std::cout << s << r.source << "\n";
        i++;
    }
    std::cout <<"\n"<< "-----------------------------------------------------" << "\n" << "\n";
    withNumbers = false;

    std::cout << "Литература без номеров:\n";
    i = 1;
    for (const Reference& r : references) {
        std::string s = withNumbers ? std::to_string(i) + ". " : "";
        std::cout << s << r.source << "\n";
        i++;
    }

    return 0;
}
