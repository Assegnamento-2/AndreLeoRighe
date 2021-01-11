# AndreLeoRighe <3


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
