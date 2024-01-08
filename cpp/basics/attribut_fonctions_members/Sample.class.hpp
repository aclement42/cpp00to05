#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample
{
    public:

    int foo;

    Sample(void);
    ~Sample(void);

    void    bar(void);
};
//une var quon a dans la class et quon peut utiliser a partir dune instance
//ici foo est une var qui existera et sera differente pour chaque instance de notte class

#endif