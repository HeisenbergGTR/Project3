#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

struct Billionaire {
    string name;
    string rank;
    string year;
    string companyFounded;
    string companyName;
    string companyRelationship;
    string companySector;
    string companyType;
    string demographicsAge;
    string demographicsGender;
    string locationCitizenship;
    string locationCountryCode;
    string locationGdp;
    string locationRegion;
    string wealthType;
    string wealthWorthInBillions;
    string wealthHowCategory;
    string wealthHowFromEmerging;
    string wealthHowIndustry;
    string wealthHowInherited;
    string wealthHowWasFounder;
    string wealthHowWasPolitical;
};

// -------- READ CSV FILE -------- //
void readCSV(const string& filename, vector<Billionaire>& data) {
    ifstream file(filename);
    if (!file.is_open()) {      // check for error opening file
        cerr << "Error when trying to open file: " << filename << endl;
        return;                 // if error, close file
    }

    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string entry;
        vector<string> values;
        
        while (getline(iss, entry, ',')) {
            values.push_back(entry);           // add csv field to values vector
        }

        // create billionaire
        Billionaire billionaire;

        // populate billionaire values
        billionaire.name = values[0];
        billionaire.rank = values[1];
        billionaire.year = values[2];
        billionaire.companyFounded = values[3];
        billionaire.companyName = values[4];
        billionaire.companyRelationship = values[5];
        billionaire.companySector = values[6];
        billionaire.companyType = values[7];
        billionaire.demographicsAge = values[8];
        billionaire.demographicsGender = values[9];
        billionaire.locationCitizenship = values[10];
        billionaire.locationCountryCode = values[11];
        billionaire.locationGdp = values[12];
        billionaire.locationRegion = values[13];
        billionaire.wealthType = values[14];
        billionaire.wealthWorthInBillions = values[15];
        billionaire.wealthHowCategory = values[16];
        billionaire.wealthHowFromEmerging = values[17];
        billionaire.wealthHowIndustry = values[18];
        billionaire.wealthHowInherited = values[19];
        billionaire.wealthHowWasFounder = values[20];
        billionaire.wealthHowWasPolitical = values[21];

        // add billionaire to data vector
        data.push_back(billionaire);
    }

    file.close();
}

// -------- SEARCH FUNCTIONS -------- //
void searchBillionaireLinearProbing(const unordered_map<string, Billionaire>& hashMapLinearProbe, const string& name) {

    auto it = hashMapLinearProbe.find(name);    // find billionaire by key (name)
    if (it != hashMapLinearProbe.end()) {       // if billionaire is present, print info
        cout << endl <<"--------- LINEAR PROBING ---------" << endl;
        cout << "Billionaire " << name << " found in Hash Map (linear probing): " << endl;
        cout << "Rank: " << it->second.rank << endl;
        cout << "Year: " << it->second.year << endl;
        cout << "Company Founded: " << it->second.companyFounded << endl;
        cout << "Company Name: " << it->second.companyName << endl;
        cout << "Company Relationship: " << it->second.companyRelationship << endl;
        cout << "Company Sector: " << it->second.companySector << endl;
        cout << "Company Type: " << it->second.companyType << endl;
        cout << "Demographics Age: " << it->second.demographicsAge << endl;
        cout << "Demographics Gender: " << it->second.demographicsGender << endl;
        cout << "Location Citizenship: " << it->second.locationCitizenship << endl;
        cout << "Location Country Code: " << it->second.locationCountryCode << endl;
        cout << "Location GDP: " << it->second.locationGdp << endl;
        cout << "Location Region: " << it->second.locationRegion << endl;
        cout << "Wealth Type: " << it->second.wealthType << endl;
        cout << "Wealth Worth In Billions: " << it->second.wealthWorthInBillions << endl;
        cout << "Wealth How Category: " << it->second.wealthHowCategory << endl;
        cout << "Wealth How From Emerging: " << it->second.wealthHowFromEmerging << endl;
        cout << "Wealth How Industry: " << it->second.wealthHowIndustry << endl;
        cout << "Wealth How Inherited: " << it->second.wealthHowInherited << endl;
        cout << "Wealth How Was Founder: " << it->second.wealthHowWasFounder << endl;
        cout << "Wealth How Was Political: " << it->second.wealthHowWasPolitical << endl;
    }
}

void searchBillionaireSeparateChaining(const unordered_map<string, list<Billionaire>>& hashMapSeparateChaining, const string& name) {

    auto it = hashMapSeparateChaining.find(name);       // find billionaire by key (name)
    if (it != hashMapSeparateChaining.end()) {          // if billionaire is present, print info
        cout << endl << "--------- SEPARATE CHAINING ---------" << endl;
        cout << "Billionaire " << name << " found in Hash Map (separate chaining): " << endl;
        for (const auto& billionaire : it->second) {
            cout << "Rank: " << billionaire.rank << endl;
            cout << "Year: " << billionaire.year << endl;
            cout << "Company Founded: " << billionaire.companyFounded << endl;
            cout << "Company Name: " << billionaire.companyName << endl;
            cout << "Company Relationship: " << billionaire.companyRelationship << endl;
            cout << "Company Sector: " << billionaire.companySector << endl;
            cout << "Company Type: " << billionaire.companyType << endl;
            cout << "Demographics Age: " << billionaire.demographicsAge << endl;
            cout << "Demographics Gender: " << billionaire.demographicsGender << endl;
            cout << "Location Citizenship: " << billionaire.locationCitizenship << endl;
            cout << "Location Country Code: " << billionaire.locationCountryCode << endl;
            cout << "Location GDP: " << billionaire.locationGdp << endl;
            cout << "Location Region: " << billionaire.locationRegion << endl;
            cout << "Wealth Type: " << billionaire.wealthType << endl;
            cout << "Wealth Worth In Billions: " << billionaire.wealthWorthInBillions << endl;
            cout << "Wealth How Category: " << billionaire.wealthHowCategory << endl;
            cout << "Wealth How From Emerging: " << billionaire.wealthHowFromEmerging << endl;
            cout << "Wealth How Industry: " << billionaire.wealthHowIndustry << endl;
            cout << "Wealth How Inherited: " << billionaire.wealthHowInherited << endl;
            cout << "Wealth How Was Founder: " << billionaire.wealthHowWasFounder << endl;
            cout << "Wealth How Was Political: " << billionaire.wealthHowWasPolitical << endl;
            cout << endl << "--------- TIME COMPLEXITY ---------" << endl;
            cout << "Time complexity of searching a separate chaining hash map: O(1)" << endl;
            cout << "Time complexity of searching a linear probing hash map: O(1)" << endl << endl;
            break;
        }
    } else {
        cout << name << " is not a billionaire." << endl << endl;
    }
}

void insertBillionaire(unordered_map<string, Billionaire>& hashMapLinearProbe, unordered_map<string, list<Billionaire>>& hashMapSeparateChaining) {
    Billionaire newBillionaire;

    // populate new billionaire data
    cout << "Enter the data for the new billionaire." << endl << "Name:";
    getline(cin, newBillionaire.name);
    newBillionaire.name = "\"" + newBillionaire.name + "\"";  // add quotation marks to match the format
    cout << "Company Name:";
    getline(cin, newBillionaire.companyName);
    cout << "Wealth Worth in Millions:";
    getline(cin, newBillionaire.wealthWorthInBillions);
    // add new properties if desired

    // add the new billionaire to the hash maps
    hashMapLinearProbe[newBillionaire.name] = newBillionaire;
    hashMapSeparateChaining[newBillionaire.name].push_back(newBillionaire);

    cout << endl << "--------- SPACE COMPLEXITY ---------" << endl;
    cout << "Space complexity of inserting in a separate chaining hash map: O(n)" << endl;
    cout << "Space complexity of inserting in a linear probing hash map: O(n + m)" << endl << endl;
}

// -------- MAIN -------- //
int main() {
    string filename = "billionaires.csv";
    vector<Billionaire> data;       // initially empty data vector

    readCSV(filename, data);

    unordered_map<string, Billionaire> hashMapLinearProbe;
    unordered_map<string, list<Billionaire>> hashMapSeparateChaining;

    for (const auto& billionaire : data) {      // populate hash maps
        hashMapLinearProbe[billionaire.name] = billionaire;
        hashMapSeparateChaining[billionaire.name].push_back(billionaire);
    }

    char searchYesNo = 'y';
    char insertYesNo = 'y';
    char exit = 'n';

    while (exit = 'n') {
        string name;
        cout << "Do you want to search for a billionaire? (y/n): " << endl;
        cin >> searchYesNo;
        cin.ignore();

        if (searchYesNo == 'n') {
            cout << "Do you want to insert a NEW billionaire? (y/n)" << endl;
            cin >> insertYesNo;
            cin.ignore();

            if (insertYesNo == 'n') {
                cout << "Do you want to exit the program? (y/n)" << endl;
                cin >> exit;
                cin.ignore();

                if (exit == 'y') {
                    break;
                }
                continue;
            }

            else if (insertYesNo == 'y') {
                insertBillionaire(hashMapLinearProbe, hashMapSeparateChaining);
                continue;
            }

            else {
                cout << "Invalid input. Please try again." << endl << endl;
                searchYesNo = 'y';
                continue;
            }
        }

        if (searchYesNo != 'y') {
            cout << "Invalid input. Please try again." << endl << endl;
            searchYesNo = 'y';
            continue;
        }

        cout << "Enter the name of the billionaire:" << endl;
        getline(cin, name);
        name = "\"" + name + "\"";      // right now, we need to add quotations for search to work
        searchBillionaireLinearProbing(hashMapLinearProbe, name);
        searchBillionaireSeparateChaining(hashMapSeparateChaining, name);
    }

    cout << endl << "Later Gator!" << endl;

    cout << R"(
                .-._   _ _ _ _ _ _ _ _
     .-''-.__.-'00  '-' ' ' ' ' ' ' ' '-.
    '.___ '    .   .--_'-' '-' '-' _'-' '._
     V: V 'vv-'   '_   '.       .'  _..' '.'.
       '=.____.=_.--'   :_.__.__:_   '.   : :
               (((____.-'        '-.  /   : :
                                 (((-'\ .' /
                               _____..'  .'
                              '-._____.-'
    )" << endl;

    //This ASCII pic can be found at
    //https://asciiart.website/index.php?art=animals/reptiles/aligators

    return 0;
}
