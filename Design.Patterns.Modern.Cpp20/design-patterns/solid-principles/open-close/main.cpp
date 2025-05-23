/**
 * The goal of the open-close principle is to avoid jumping back to code you
 * have already written (mod), you do so by making your code extendable.
 */
#include <boost/lexical_cast.hpp>
#include <boost/mpl/assert.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace boost;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
  string name;
  Color color;
  Size size;
};

/**
 * Bad approach of a filter, you have to modify this struct for every filtering
 * option
 */
struct ProductFilter {
  vector<Product *> by_color(vector<Product *> items, Color color) {
    vector<Product *> result;
    for (auto &i : items) {
      if (i->color == color) {
        result.push_back(i);
      }
    }
    return result;
  }

  vector<Product *> by_size(vector<Product *> items, Size size) {
    vector<Product *> result;
    for (auto &i : items) {
      if (i->size == size) {
        result.push_back(i);
      }
    }
    return result;
  }

  // by_color_and_size
  // by_name
  // etc...
};

template <typename T> struct Specification {
  virtual bool is_satisfied(T *item) = 0;
};

template <typename T> struct Filter {
  virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

/**
 * This should be a better filter in terms of extendability
 */
struct BetterFilter : Filter<Product> {
  vector<Product *> filter(vector<Product *> items,
                           Specification<Product> &spec) override {
    vector<Product *> result;
    for (auto &item : items) {
      if (spec.is_satisfied(item)) {
        result.push_back(item);
      }
    }

    return result;
  }
};

struct ColorSpecification : Specification<Product> {
  Color color;
  ColorSpecification(Color color) : color(color) {}
  bool is_satisfied(Product *item) override { return item->color == color; }
};

struct SizeSpecification : Specification<Product> {
  Size size;
  SizeSpecification(Size size) : size(size) {}
  bool is_satisfied(Product *item) override { return item->size == size; }
};

template <typename T> struct AndSpecification : Specification<T> {
  Specification<T> &first;
  Specification<T> &second;
  AndSpecification(Specification<T> &first, Specification<T> &second)
      : first(first), second(second) {}

  bool is_satisfied(T *item) override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

int main() {
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};

  vector<Product *> items{&apple, &tree, &house};

  // example with base not-so-good filter
  // ProductFilter pf;
  // auto green_things = pf.by_color(items, Color::green);
  // for (auto &item : green_things) {
  //   cout << item->name << " is green" << endl;
  // }

  BetterFilter bf;
  ColorSpecification green(Color::green);

  for (auto &item : bf.filter(items, green)) {
    cout << item->name + " is green" << endl;
  }

  SizeSpecification large(Size::large);
  AndSpecification<Product> green_and_large(green, large);

  for (auto &item : bf.filter(items, green_and_large)) {
    cout << item->name + " is green and large" << endl;
  }

  return 0;
}
