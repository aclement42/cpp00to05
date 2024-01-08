#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample
{
    public:

    int foo;//var de type int

    Sample(void);//decla construct
    ~Sample(void);//decla destruct

    void    bar(void);//fonction
};
//une var quon a dans la class et quon peut utiliser a partir dune instance
//ici foo est une var qui existera et sera differente pour chaque instance de notte class

#endif