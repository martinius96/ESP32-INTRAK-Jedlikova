# ESP32-INTRAK-Jedlikova
* Pripojenie na sieť INTRAK a následné pripojenie na web
* Skúšané na Jedlikovej 9
* Funguje pod RADIUS serverom, pod TACACS-om nie.

# Metódy overenia
* 1. krok PEAP
* 2. krok MsCHAPv2

# Overená - testovacia doska
* ESP32 Devkit v1 DOIT

# Postup
* Nahrajte sketch getmac.ino do dosky ESP32
* Získanú MAC adresu si zapíšte
* Prihlásenie do UserPanelu --> https://userpanel.pcklub.sk/
![alt text](https://i.nahraj.to/f/23Yv.PNG)
* Získanú MAC adresu vpíšeme do wifi pripojenia a počkáme na jeho schválenie
![alt text](https://i.nahraj.to/f/23Yx.PNG)
# Finálny sketch
* Pred nahratím sketchu login.ino je potrebné zmeniť používateľské meno v tvare: meno.priezvisko a vaše heslo do siete INTRAK
* Zmeniť meno zariadenia v sieti (podľa mena počítača z Userpanelu)

