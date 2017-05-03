#include <iostream>

class I {
public:
  virtual ~I(){}
  virtual void do_it() = 0;
};

class A: public I {
public:
  ~A() {
    std::cout << "A dtor" << '\n';
  }
  /*virtual*/
  void do_it() {
    std::cout << 'A';
  }
};

class D: public I {
public:
  D(I *inner) {
    m_wrappee = inner;
  }
  ~D() {
    delete m_wrappee;
  }
  /*virtual*/
  void do_it() {
    m_wrappee->do_it();
  }
private:
  I *m_wrappee;
};

class X: public D {
public:
  X(I *core): D(core){}
  ~X() {
    std::cout << "X dtor" << "   ";
  }
  /*virtual*/
  void do_it() {
    D::do_it();
    std::cout << 'X';
  }
};

class Y: public D {
public:
  Y(I *core): D(core){}
  ~Y() {
    std::cout << "Y dtor" << "   ";
  }
  /*virtual*/
  void do_it() {
    D::do_it();
    std::cout << 'Y';
  }
};

class Z: public D {
public:
  Z(I *core): D(core){}
  ~Z() {
    std::cout << "Z dtor" << "   ";
  }
  /*virtual*/
  void do_it() {
    D::do_it();
    std::cout << 'Z';
  }
};

int main() {
  I *anX = new X(new A);
  I *anXY = new Y(new X(new A));
  I *anXYZ = new Z(new Y(new X(new A)));
  anX->do_it();
  std::cout << '\n';
  anXY->do_it();
  std::cout << '\n';
  anXYZ->do_it();
  std::cout << '\n';
  delete anX;
  delete anXY;
  delete anXYZ;
}
