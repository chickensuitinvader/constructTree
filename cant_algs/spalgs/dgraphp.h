#ifndef DGRAPHP_H
#define DGRAPHP_H
/* Directed Graph Provider - Interface Class
 * ----------------------------------------------------------------------------
 * Author:  Shane Saunders
 */
 
class DGraph;  // graph class

/*--- Graph Provider Interface Class (for experiments) ----------------------*/
class DGraphProvider {
  public:
    virtual ~DGraphProvider() { }
    
    virtual char *description() = 0;
    virtual char *varLabel() = 0;    
    virtual void inputParameters() = 0;

    virtual DGraph *generateGraph() = 0;
    virtual int currentGraphSize() = 0;

    virtual double varValue() = 0;    
    virtual void initVar() = 0;
    virtual void updateVar() = 0;
    virtual bool varLimitReached() = 0;
};
#endif
