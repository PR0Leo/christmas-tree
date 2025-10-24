# Codestruktur verstehen:
## Einführung
Um Code zu schreiben gibt es verschiedene "coding languages". Je nach Anwendung
benutzt man eine andere. Wir programmieren in "CPP"("C Plus Plus" oder "C++"), 
was man als Low-Level bezeichnet, da die Funktionen nicht Abstrakt sind sondern
probieren den MCU (Mikrocontroller) konkret Befehle zu diktieren.
Der MCU führt in der Regel einen Befehl nach dem anderen aus und so 
strukturieren wir auch unser Programm.
## 1. Main oder Loop Funktion
Wir fangen an mit der Main, aber da wir einen Arduino als MCU benutzten der 
leicht für Anfänger ist heißt es nicht Main sondern Loop, welche wie der Name 
auch sagt sich immer wieder wiederholt.
In der Loop führen wir sequenziel Befehle durch, wie in dem Beispiel [[]]
Dafür benutzen wir Befehle. Damit der MCU diese Befehle auch interpretieren kann
fügen wir Libaries (Bibliotheken) hinzu.
## 2. #include <header-to-libary.h>
Diese Libaries werden nicht als ganzes im Code nieder geschrieben, sondern auf 
diese wird nur mittels eines Links(Headers) verwiesen. Ein Beispiel sieht man im 
Bild bei "2.".
## 3. Setup Funktion
Natürlich können wir in der Loop Funktion nicht einfach sagen: Mach rote LED an. 
Wie gesagt, "C++" ist eine Low Level Language und es muss alles konkret 
deklariert sein. Was ist eine LED? Wie gehe ich mit dieser LED um?, fragt sich 
der MCU. 
Deshalb brauchen wir ein bisschen Vorbereitung, welche mir in der Setup Funktion
treffen. Dazu setzten wir den Modus der "GPIOs". "GPIOs" sind "Generell Purpose 
In- and Outputs". Zum Beispiel(im Bild unter 3. zu sehen), mittels 
pinMode(GRN_LED, OUTPUT);
setzen wir den Modus von Pin "GRN_LED" als Ausgang(Output). "ABER GRN_LED is 
doch gar kein Pin". Deshalb ließ das nächste Chapter. 
## 4. #define 
Um den Code nun leserlicher zu machen, definieren wir zum Beispiel "GRN_LED" als 
"2", mittels
#define GRN_LED 2;
wie im Bild bei 4. zu sehen ist. Später wenn der Code durchgeführt wird, wird 
zuerst jede Stelle, an der GRN_LED steht mit 2 ersetzt. Das hat wie gesagt den 
Vorteil, dass der Code leserlicher wird, weil keine unbekannten Zahlen - in 
Englisch auch "Magic Numbers" genannt - im Code stehen. Zudem kann man bei der 
Entwicklung die GRN_LED auch schnell auf einen anderen Pin legen indem man im 
Code nur an einer Stelle, beim "define" die 2 mit einer 3 ersetzt. Deshalb 
stehen die defines auch am Anfang.
## 5. Funktionen definieren
Fast Geschaft, fehlt nur noch die Funktion. Äh, Funktion hat es schon, aber wie 
man eine Funktion halt schreibt.
Funktionen machen Befehle wiederverwendbar und das Hauptprogramm wird dadurch  
leichter zu lesen. So führt die Funktion im Bild bei 5. dazu, dass die LED eine 
Sekunde ein und dann eine Sekunde ausgeschalten wird. Wir ihr in der Loop sehen 
könnt wird diese übersichtlicher. Man sparrt sich die Befehle für die grüne 
und rote Led zu schreiben, da ich der Funktion meinen LED_PIN übergebe, 
welche universall für die grüne und rote LED zu benutzen ist.

