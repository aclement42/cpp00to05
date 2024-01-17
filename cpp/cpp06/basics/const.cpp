//permet de transformer les qualifiers de types
// a ne pas utiliser de trop; doit avoir bonne raison

int     main()
{
    int     a = 42;

    int const * b = &a; //promotion implicit -->OK passer dune valeur mutable a une const = ok

    int         * c = b; // implicit demotion --> NOP

    int         * d = const_cast<int *>(b); //explicit demotion --> ok //effectue ce changement de qualifer de type
                    //<type que lon veut> (le mutable)


    return (0);
}