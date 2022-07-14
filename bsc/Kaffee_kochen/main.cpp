#include "KaffeMaschine.h"
#include "KaffeMaschineDeluxe.h"

#include <iostream>
using namespace std;

/* -- */
void prettyprint(KaffeMaschine &maschine) {

	cout << "--- WILKOMMEN BEI DER KAFFEMASCHINE ---" << endl
		<< "HIER SEHEN SIE DAS INNERE DER MASCHINE" << endl;

	maschine.info();

	cout << "--- HERZLICHEN DANK FUER IHR INTERESSE ---" << endl;
}


int main() {


	KaffeMaschine HrRakersSeineMaschine(10.0,10.0); // <-- Hier Konstruktoraufruf!
	prettyprint(HrRakersSeineMaschine);

#if 0
	HrRakersSeineMaschine.info();

	HrRakersSeineMaschine.an(9,KaffeMaschine::gross);
	HrRakersSeineMaschine.info();
	
	HrRakersSeineMaschine.aus();
	HrRakersSeineMaschine.info();
#endif

	KaffeMaschineDeluxe HrVonBarsSeineMaschine(5., 3., 0.5);
	prettyprint(HrVonBarsSeineMaschine);

#if 0
	HrVonBarsSeineMaschine.info();

	HrVonBarsSeineMaschine.an(2, KaffeMaschine::gross, KaffeMaschineDeluxe::kakao);

	HrVonBarsSeineMaschine.info();
#endif

	getchar();
	return 0;
}