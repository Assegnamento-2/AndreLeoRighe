L'intero è realizzato con VS Code. 
L'utilizzo di CMake ha causato problemi che non sono stati risolti.
In lettura della time table, l'unico dato che invalida il treno è il nome; gli altri dati vengono eventualmente sostituiti da valori validi (ossia se un treno presenta un valore per il tipo non valido viene considerato come Regionale).
Il transito di treni Veloci e Superveloci per stazioni locali non è gestito correttamente.
I nomi delle stazioni non possono contenere spazi.


messaggi durante la gestione di dati non validi dei check/scrivere che per scelta settiamo i trani a superveloci etc
nomi di stazioni con spazi
gestire treni partiti dopo mezzanotte
move constructor(?) FATTO
wait>5?
riatrdi?

bool RailwayLine::is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

se i treni partono dopo il minuto 1440 bisogna ignorarli
