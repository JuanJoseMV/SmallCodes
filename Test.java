/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package segmentos;

/**
 *
 * @author emarq
 */
public class Test {

    static public String escribir(int n, int p) {

        if (n == 0) {
            return "";
        }

        String respuesta = "";
        int aux = n;
        int udc = n / 100;

        if (n > 99) {
            switch (udc) {
                case 1:
                    if (n == 100) {
                        respuesta = respuesta.concat("cien ");
                    } else {
                        respuesta = respuesta.concat("ciento ");
                    }
                    break;
                case 2:
                    respuesta = respuesta.concat("doscientos ");
                    break;
                case 3:
                    respuesta = respuesta.concat("trescientos ");
                    break;
                case 4:
                    respuesta = respuesta.concat("cuatrocientos ");
                    break;
                case 5:
                    respuesta = respuesta.concat("quinientos ");
                    break;
                case 6:
                    respuesta = respuesta.concat("seiscientos ");
                    break;
                case 7:
                    respuesta = respuesta.concat("setecientos ");
                    break;
                case 8:
                    respuesta = respuesta.concat("ochocientos ");
                    break;
                case 9:
                    respuesta = respuesta.concat("novecientos ");
                    break;
            }

            aux = n % 100;
        }

        if (aux > 9) {
            udc = aux / 10;
            if (aux < 16 && aux != 10) {
                switch (aux) {
                    case 11:
                        respuesta = respuesta.concat("once ");
                        break;
                    case 12:
                        respuesta = respuesta.concat("doce ");
                        break;
                    case 13:
                        respuesta = respuesta.concat("trece ");
                        break;
                    case 14:
                        respuesta = respuesta.concat("catorce ");
                        break;
                    case 15:
                        respuesta = respuesta.concat("quince ");
                        break;
                }
            } else {
                switch (udc) {
                    case 1:
                        if (aux == 10) {
                            respuesta = respuesta.concat("diez ");
                        } else {
                            respuesta = respuesta.concat("dieci");
                        }
                        break;
                    case 2:
                        if (aux == 20) {
                            respuesta = respuesta.concat("veinte ");
                        } else {
                            respuesta = respuesta.concat("veinti");
                        }
                        break;
                    case 3:
                        if (aux == 30) {
                            respuesta = respuesta.concat("treinta ");
                        } else {
                            respuesta = respuesta.concat("treintai");
                        }
                        break;
                    case 4:
                        if (aux == 40) {
                            respuesta = respuesta.concat("cuarenta ");
                        } else {
                            respuesta = respuesta.concat("cuarentai");
                        }
                        break;
                    case 5:
                        if (aux == 50) {
                            respuesta = respuesta.concat("cincuenta ");
                        } else {
                            respuesta = respuesta.concat("cincuetai");
                        }
                        break;
                    case 6:
                        if (aux == 60) {
                            respuesta = respuesta.concat("sesenta ");
                        } else {
                            respuesta = respuesta.concat("sesentai");
                        }
                        break;
                    case 7:
                        if (aux == 70) {
                            respuesta = respuesta.concat("setenta ");
                        } else {
                            respuesta = respuesta.concat("setentai");
                        }
                        break;
                    case 8:
                        if (aux == 80) {
                            respuesta = respuesta.concat("ochenta ");
                        } else {
                            respuesta = respuesta.concat("ochentai");
                        }
                        break;
                    case 9:
                        if (aux == 90) {
                            respuesta = respuesta.concat("noventa ");
                        } else {
                            respuesta = respuesta.concat("noventai");
                        }
                        break;
                }
            }
            aux %= 10;
        }

        if (aux > 0 && n != 1) {
            udc = aux;
            switch (udc) {
                case 1:
                    if (p == 0) {
                        respuesta = respuesta.concat("uno ");
                    } else {
                        respuesta = respuesta.concat("un ");
                    }
                    break;
                case 2:
                    respuesta = respuesta.concat("dos ");
                    break;
                case 3:
                    respuesta = respuesta.concat("tres ");
                    break;
                case 4:
                    respuesta = respuesta.concat("cuatro ");
                    break;
                case 5:
                    respuesta = respuesta.concat("cinco ");
                    break;
                case 6:
                    respuesta = respuesta.concat("seis ");
                    break;
                case 7:
                    respuesta = respuesta.concat("siete ");
                    break;
                case 8:
                    respuesta = respuesta.concat("ocho ");
                    break;
                case 9:
                    respuesta = respuesta.concat("nueve ");
                    break;
            }
        }

        switch (p) {
            case 1:
                respuesta = respuesta.concat("mil ");
                break;
            case 2:
                if (n == 1) {
                    respuesta = respuesta.concat("un millón ");
                } else {
                    respuesta = respuesta.concat("millones ");
                }
                break;
            case 3:
                if (n == 1) {
                    respuesta = respuesta.concat("un millardo ");
                } else {
                    respuesta = respuesta.concat("millardos ");
                }
                break;
            case 4:
                if (n == 1) {
                    respuesta = respuesta.concat("un billón ");
                } else {
                    respuesta = respuesta.concat("billones ");
                }
                break;
            case 5:
                if (aux == 50) {
                    respuesta = respuesta.concat("un billardo ");
                } else {
                    respuesta = respuesta.concat("billardos ");
                }
                break;
            case 6:
                if (aux == 60) {
                    respuesta = respuesta.concat("un trillón ");
                } else {
                    respuesta = respuesta.concat("trillones ");
                }
                break;
            case 7:
                if (aux == 70) {
                    respuesta = respuesta.concat("un trillardo ");
                } else {
                    respuesta = respuesta.concat("trillardos ");
                }
                break;
            case 8:
                if (aux == 80) {
                    respuesta = respuesta.concat("un cuatrillón ");
                } else {
                    respuesta = respuesta.concat("cuatrillones ");
                }
                break;
        }
        return respuesta;
    }

    public static void main(String[] args) {
        final int max = Integer.MAX_VALUE;
        int aux = max;
        int paq = 0;
        int periodos = 0;
        String ans = "";

        while (aux > 100) {
            paq = aux % 1000;
            aux = aux / 1000;
            ans = ans.concat(escribir(paq, periodos));
            periodos++;
        }

        ans = ans.concat(escribir(aux, periodos));
        System.out.println(ans);
    }
}
