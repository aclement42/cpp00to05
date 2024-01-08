#ifndef SAMPLE_CLASS_H 
# define SAMPLE_CLASS_H

class Sample 
{
public:

    int publicFoo;
    Sample(void);
    ~Sample(void);

    void    publicBar(void)const;

private:

    int _privateFoo;

    void    _privateBar(void)const;
};

//visible uniquement depuis linterieur de la class ou depuis lext
//public:int + ext
//private: uniquement int

#endif