#include <iostream>
using namespace std;

// An arbitrary interface is defined to serve as a bridge between a possible 2x2
// scenario (circle, square, vector and raster)
struct Renderer {
  virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : Renderer {
  void render_circle(float x, float y, float radius) override {
    cout << "Drawing a vector circle of radius " << radius << endl;
  }
};

struct RasterRenderer : Renderer {
  void render_circle(float x, float y, float radius) override {
    cout << "Rasterizing a circle of radius " << radius << endl;
  }
};

struct Shape {
protected:
  Renderer &renderer;
  Shape(Renderer &renderer) : renderer{renderer} {}

public:
  virtual void draw() = 0;
  virtual void resize(float factor) = 0;
};

struct Circle : Shape {
  float x, y, radius;
  void draw() override { renderer.render_circle(x, y, radius); }
  void resize(float factor) override { radius *= factor; }

  Circle(Renderer &renderer, float x, float y, float radius)
      : Shape{renderer}, x{x}, y{y}, radius{radius} {}
};

int main() {
  RasterRenderer rr;
  Circle raster_circle{rr, 5, 5, 5};
  raster_circle.draw();
  raster_circle.resize(2);
  raster_circle.draw();

  return 0;
}
