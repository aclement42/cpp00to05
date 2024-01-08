#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H

struct Sample1
{
    int Foo;

    Sample1(void);
    ~Sample1(void);

    void    bar(void)const;
};

//difference avec une class: il ny a pas public/private
//a un scoop par default public
#endif