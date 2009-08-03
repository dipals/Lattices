// -*- C++ -*-

#include <iostream>

class a_node {
  friend std::ostream& operator<<(std::ostream&, const a_node&);

public:
  std::string s;
  char c;

  a_node(std::string s, char c) : s(s), c(c) {
  }

  virtual ~a_node() {
  }

protected:
  virtual std::ostream& printit(std::ostream& os) const {
    os << "(" << s << ", " << (c ? std::string(1, c) : "null") << ")";
    return os;
  }
};

std::ostream&
operator<<(std::ostream& os, const a_node& an)
{
  return an.printit(os);
}

// A binary tree is named/denoted by its root.  No tree balancing is attempted.
//
class binary_tree {

  friend std::ostream& operator<<(std::ostream&, const binary_tree&);

public:
  binary_tree(const a_node& t) : node(t), left(0), right(0) {
  }

  virtual ~binary_tree() {
  }

  void attach_left(binary_tree *const t_left) {
    left = t_left;
  }

  void attach_right(binary_tree *const t_right) {
    right = t_right;
  }

protected:
  virtual std::ostream& printit(std::ostream& os) const {
    os << "Node = " << node << std::endl;

    os << "Left subtree: ";
    if (left)
      os << std::endl << *left;
    else
      os << "-|";

    os << std::endl;

    os << "Right subtree: ";
    if (right)
      os << std::endl << *right;
    else
      os << "-|";

    return os;
  }

private:
  a_node node;
  binary_tree *left;
  binary_tree *right;
};

// inline
std::ostream&
operator<<(std::ostream& os, const binary_tree& t)
{
  return t.printit(os);
}
