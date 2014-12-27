#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //deschide fisierul
    ofstream myfile;
    myfile.open ("list.txt");
    
    int run = 1, gataHala;
    
    while(run == 1) {
    	int hala, randul, startRand, endRand, nivel, nrNivele, coloana, startColoane, endColoane;
    	int raspuns;
        
        cout << "Introduceti nr halei: ";
        cin >> hala;
        
        gataHala = 0;
        
        while (gataHala == 0) {
            cout << "De la randul: ";
            cin >> startRand;
            cout << "Pana la randul: ";
            cin >> endRand;
            
            cout << "Nr de nivele: ";
            cin >> nrNivele;
            
            cout << "De la coloana: ";
            cin >> startColoane;
            cout << "Pana la coloana: ";
            cin >> endColoane;
            
    		for (randul = startRand; randul <= endRand; randul++) {
    			for (nivel = 1; nivel <= nrNivele;nivel++) {
    				for (coloana = startColoane; coloana <= endColoane; coloana++) {
    				    if (nivel != 1 && coloana == 0) coloana++;
    					myfile << "H"<<hala<<"-R"<<randul<<"-N"<<nivel<<"-C"<<coloana<<endl;
    				}
    			}
    		}
    		
    		while (true) {
        		cout << "Gata! Urmatorul lucru:" << endl;
        		cout << "/t1. Continua hala.." << endl;
        		cout << "/t2. Printeaza DEP-uri.." << endl;
        		cout << "/t3. Hala urmatoare.." << endl;
        		cout << "/t4. Gata, inchide!" << endl;
        		cin >> raspuns;
        		
        		if(raspuns == 1) {
        		    break;
        		}
        		else if(raspuns == 2) {
        		    int nrDep;
        		    cout << "Introduceti nr de DEP-uri: ";
        		    cin >> nrDep;
        		    for (int ix = 1; ix <= nrDep; ix++) {
        		        myfile << "H"<<hala<<"-DEP"<<ix<<endl;
        		    }
        		}
        		else if (raspuns == 3) {
        		    gataHala = 1;
        		    break;
        		}
        		else if (raspuns == 4) {
        		    gataHala = 1;
        		    run = 0;
        		}
    		}
        }
    }
	
    myfile.close();
    cout <<"Cya!";
	
	return 0;
}