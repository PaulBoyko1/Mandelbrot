#include "ComplexPlane.h"


ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight) {
    
    m_pixel_size = {pixelWidth, pixelHeight};
    m_aspectRatio = (float)pixelWidth / pixelHeight;
    m_plane_center = {0, 0};
    m_plane_size = {BASE_WIDTH, BASE_HEIGHT * m_aspectRatio};
    m_zoomCount = 0;
    m_State = State::CALCULATING;
    m_vArray.setPrimitieType(Points);
    m_vArray.resize(pixelWidth * pixelHeight);

}
void ComplexPlane::draw(RenderTarget& target, RenderStates states) const {

    target.draw(m_vArray, states);

}
void ComplexPlane::updateRender() {

    if (m_State == State::Calculating) {
        for (int i = 0; i < m_pixel_size.y; i++) {
            for (int j = 0; j < m_pixel_size.x; j++) {
                m_vArray[j + i * m_pixel_size.x].position = { (float)j,(float)i };
                Vector2f curr_pixel = mapPixelToCoords(Vector2f(j, i));
                size_t num_iterations = countIterations(curr_pixel);
                Uint8 r, g, b;
                iterationsToRGB(num_iterations, r, g, b);
                m_vArray[j + i * m_pixel_size.x].color = Color(r, g, b);
            }
        }
        m_state = State::Displaying;
    }

}
void ComplexPlane::zoomIn() {

    m_zoomCount++;
    double x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
    double y = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
    m_plane_size = Vector2f(x, y);
    m_state = State::CALCULATING;

}
void ComplexPlane::zoomOut() {

    m_zoomCount -= 1;
    double x = BASE_WIDTH * (pow(BASE_ZOOM, m_zoomCount));
    double y = BASE_HEIGHT * m_aspectRatio * (pow(BASE_ZOOM, m_zoomCount));
    m_plane_size = Vector2f(x, y);
    m_state = State::CALCULATING;

}
void ComplexPlane::setCenter(Vector2i mousePixel) {
    m_plane_center = mapPixelToCoords(mousePixel);
    m_state = State::CALCULATING;
}
void ComplexPlane::setMouseLocation(Vector2i mousPixel) {
     m_mouseLocation = mapPixelToCoords(pixel);
}
void ComplexPlane::loadText(Text& text) {
    stringstream ss;
    ss << "Mandelbrot Set" << endl;
    ss << "Center: (" << m_plane_center.x << ", " << m_plane_center.y << ")" << endl;
    ss << "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")" << endl;
    ss << "Left-click to Zoom in" << endl;
    ss << "Right-click to Zoom out" << endl;
    text.setString(ss.str());
}
size_t ComplexPlane::countIterations(Vector2f coord) {
    complex<float> c(coord.x, coord.y);
    complex<float> z(0, 0);

    int iter = 0;

    while (abs(z) <= 2.0f && iter < MAX_ITER)
    {
        z = z * z + c;
        iter++;
    }

    return iter;
}
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) {
    if (count >= MAX_ITER) 
    { 
        r = g = b = 0; 
        return; 
    }

    float n = (float)count / MAX_ITER;

    if (n < 0.2) {
        r = 128;
        g = 0;
        b = 128;
    }
    else if (n < 0.4) {
        r = 64;
        g = 224;
        b = 208;
    }
    else if (n < 0.6) {
        r = 0;
        g = 225;
        b = 0;
    }
    else if (n < 0.8f) {
        r = 255;
        g = 255;
        b = 0;
    }
    else {
        r = 255;
        g = 0;
        b = 0;
    }
}
Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel) {
    float left = m_plane_center.x - m_plane_size.x / 2.f;
    float top  = m_plane_center.y - m_plane_size.y / 2.f;

    float x = ((float)mousePixel.x / m_pixel_size.x) * m_plane_size.x + left;
    float y = ((float)(m_pixel_size.y - mousePixel.y) / m_pixel_size.y) * m_plane_size.y + top;

    return Vector2f(x, y);
}
