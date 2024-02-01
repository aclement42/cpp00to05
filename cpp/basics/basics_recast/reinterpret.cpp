//pouvoir reinterpreter nimporte quelle adresse en nimport quelle autre adreesse

int     main()
{
    float   a = 420.042f;

    void    * b = &a; //implicit promotion -> ok; //void* pour prendre l'adresse de notre floatant a
    
    int     * c = reinterpret_cast<int *>(b);// explicit demotion --> ok, i obey

    int     & d = reinterpret_cast<int &>(b);// explicit demotion --> ok, i obey
    //ca va compiler mais attention aux resultats escomptes!!!! 
    return (0);
}