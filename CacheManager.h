
#ifndef ED2_CACHEMANAGER_H
#define ED2_CACHEMANAGER_H


class CasheManager {

 public:


  virtual void save() = 0;
  virtual bool check() = 0;
  virtual void get() = 0;


};


#endif //ED2_CACHEMANAGER_H
