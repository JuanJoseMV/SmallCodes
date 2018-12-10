
#include <iostream>
#include <limits>

using namespace std;

/**
 * M�todo para escribir paquetes de 3 cifras. 
 * n es el n�mero de 3 cifras.
 * p es el periodo en el que est�, si p = 0, son las primeras 3 cifras del n�mero. Si p = 1, son las de mil. Si p = 2, son las de mill�n...
 **/

string escribir(int n, int p) {



        if (n == 0) { //si es cero, no tomar en cuenta.

            return "";

        }



        string respuesta = "";

        int aux = n;

        int udc = n / 100; //unidades, decenas, centenas. En el primer caso representan las centenas, que ser�a el n�mero de la izquierda.
                            //si el n�mero es 123, 123 / 100 da 1.


        if (n > 99) { //para el caso de los "cientos"

            switch (udc) { //mirar qu� caso estamos tratando, en caso de que el n�mero de la izquierda sea 1, 2, 3...

                case 1:

                    if (n == 100) { //si el n�mero es cien cerrado, se escribe "cien". Sino, debe ser "ciento" algo.

                        respuesta = respuesta + "cien "; //la respuesta empieza vac�a y se le van agregando los valores.

                    } else {

                        respuesta = respuesta + "ciento ";

                    }

                    break; //el break termina el switch, deja de evaluar los otros casos.

                case 2:

                    respuesta = respuesta + "doscientos ";

                    break;

                case 3:

                    respuesta = respuesta + "trescientos ";

                    break;

                case 4:

                    respuesta = respuesta + "cuatrocientos ";

                    break;

                case 5:

                    respuesta = respuesta + "quinientos ";

                    break;

                case 6:

                    respuesta = respuesta + "seiscientos ";

                    break;

                case 7:

                    respuesta = respuesta + "setecientos ";

                    break;

                case 8:

                    respuesta = respuesta + "ochocientos ";

                    break;

                case 9:

                    respuesta = respuesta + "novecientos ";

                    break;

            }



            aux = n % 100; // n % 100 (n mod 100) nos da los otros dos n�meros. Si el n�mero es 123, 123 % 100 no da 23. 

        }



        if (aux > 9) {

            udc = aux / 10; //con esto tomamos las decenas. Si el n�mero es 23, 23 / 10 da 2.

            if (aux < 16 && aux != 10) { //este caso es para evaluar los n�meros del 11 al 15 que son diferentes.

                switch (aux) { //hay que evaluar la parte de las decenas para esto.

                    case 11:

                        respuesta = respuesta + "once ";

                        break;

                    case 12:

                        respuesta = respuesta + "doce ";

                        break;

                    case 13:

                        respuesta = respuesta + "trece ";

                        break;

                    case 14:

                        respuesta = respuesta + "catorce ";

                        break;

                    case 15:

                        respuesta = respuesta + "quince ";

                        break;

                }

            } else {// en caso de que sea m�s de 15.

                switch (udc) { //se eval�a la cifra de las decenas.

                    case 1:

                        if (aux == 10) { //si es 10 exacto 

                            respuesta = respuesta + "diez ";

                        } else {

                            respuesta = respuesta + "dieci";

                        }

                        break;

                    case 2:

                        if (aux == 20) {//si es 20 exacto 

                            respuesta = respuesta + "veinte ";

                        } else {

                            respuesta = respuesta + "veinti";

                        }

                        break;

                    case 3:

                        if (aux == 30) {//si es 30 exacto 

                            respuesta = respuesta + "treinta ";

                        } else {

                            respuesta = respuesta + "treintai";

                        }

                        break;

                    case 4:

                        if (aux == 40) {//...

                            respuesta = respuesta + "cuarenta ";

                        } else {

                            respuesta = respuesta + "cuarentai";

                        }

                        break;

                    case 5:

                        if (aux == 50) {

                            respuesta = respuesta + "cincuenta ";

                        } else {

                            respuesta = respuesta + "cincuetai";

                        }

                        break;

                    case 6:

                        if (aux == 60) {

                            respuesta = respuesta + "sesenta ";

                        } else {

                            respuesta = respuesta + "sesentai";

                        }

                        break;

                    case 7:

                        if (aux == 70) {

                            respuesta = respuesta + "setenta ";

                        } else {

                            respuesta = respuesta + "setentai";

                        }

                        break;

                    case 8:

                        if (aux == 80) {

                            respuesta = respuesta + "ochenta ";

                        } else {

                            respuesta = respuesta + "ochentai";

                        }

                        break;

                    case 9:

                        if (aux == 90) {

                            respuesta = respuesta + "noventa ";

                        } else {

                            respuesta = respuesta + "noventai";

                        }

                        break;

                }

            }

            aux = aux % 10; //aqu� ya se eval�a el �ltimo n�mero. Si era 23, 23 % 10 da 3.

        }



        if (aux > 0 && n != 1) {

            udc = aux;//las unidades coinciden con el auxiliar.

            switch (udc) {//evaluamos el �ltimo d�gito

                case 1:

                    if (p == 0) { //en caso de que sea 1 y sea el �ltimo n�mero de todos (el final). Por ejemplo, si fuera 654321.

                        respuesta = respuesta + "uno ";

                    } else {

                        respuesta = respuesta + "un ";

                    }

                    break;

                case 2:

                    respuesta = respuesta + "dos ";

                    break;

                case 3:

                    respuesta = respuesta + "tres ";

                    break;

                case 4:

                    respuesta = respuesta + "cuatro ";

                    break;

                case 5:

                    respuesta = respuesta + "cinco ";

                    break;

                case 6:

                    respuesta = respuesta + "seis ";

                    break;

                case 7:

                    respuesta = respuesta + "siete ";

                    break;

                case 8:

                    respuesta = respuesta + "ocho ";

                    break;

                case 9:

                    respuesta = respuesta + "nueve ";

                    break;

            }

        }



        switch (p) { //evaluamos en qu� periodo est�n los n�meros. Si est� en la parte de miles, de millones, etc...

            case 1:

                respuesta = respuesta + "mil ";

                break;

            case 2:

                if (n == 1) {//en caso de que el n�mero sea s�lo 1. Por ejemplo: 654.001.231.654, ese uno ser�a singular.

                    respuesta = respuesta + "un mill�n ";

                } else {

                    respuesta = respuesta + "millones ";

                }

                break;

            case 3:

                if (n == 1) {

                    respuesta = respuesta + "un millardo ";

                } else {

                    respuesta = respuesta + "millardos ";

                }

                break;

            case 4:

                if (n == 1) {

                    respuesta = respuesta + "un bill�n ";

                } else {

                    respuesta = respuesta + "billones ";

                }

                break;

            case 5:

                if (n == 1) {

                    respuesta = respuesta + "un billardo ";

                } else {

                    respuesta = respuesta + "billardos ";

                }

                break;

            case 6:

                if (n == 1) {

                    respuesta = respuesta + "un trill�n ";

                } else {

                    respuesta = respuesta + "trillones ";

                }

                break;

            case 7:

                if (n == 1) {

                    respuesta = respuesta + "un trillardo ";

                } else {

                    respuesta = respuesta + "trillardos ";

                }

                break;

            case 8:

                if (n == 1) {

                    respuesta = respuesta + "un cuatrill�n "; //en espa�ol y en la escala larga, s�lo se escribe hasta cuatrill�n. De resto se usa notaci�n cient�fica.

                } else {

                    respuesta = respuesta + "cuatrillones ";

                }

                break;

        }

        return respuesta; //se devuelve el resultado.

    }

int main()
{
    int max = std::numeric_limits<int>::max();; //se usa para encontrar el valor del n�mero m�s grande del int, hay que incluir la libreria <limits>. Lo encontr� en internet.

        int aux = max;

        int paq = 0;

        int periodos = 0;

        string ans = "";



        while (aux > 100) { //ir recorriendo por paquetes de 3 cifras.

            paq = aux % 1000; //Toma las 3 cifras del n�mero a la derecha. Por ejemplo, si es 987.654.321 % 1000 = 321.

            aux = aux / 1000; //Toma el resto a la izquierda. Por ejemplo, si es 987.654.321 / 1000 = 987.654.

            ans = escribir(paq, periodos) + ans; //usa el m�todo para escribir de a tres cifras y lo va agregando a la respuesta.

            periodos++; //va contando los periodos.

        }

        ans = escribir(aux, periodos) + ans; //escribe las �ltimos 3 cifras. Las m�s significativas.
        
        cout << ans; //imprime la respuesta.
}
