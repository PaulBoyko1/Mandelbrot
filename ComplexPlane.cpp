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

    target.draw(m_vArray);

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

}
void ComplexPlane::zoomOut() {



}
void ComplexPlane::setCenter(Vector2i mousePixel) {


    
}
void ComplexPlane::setMouseLocation(Vector2i mousPixel) {



}
void ComplexPlane::loadText(Text& text) {



}
size_t ComplexPlane::countIterations(Vector2f coord) {



}
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) {



}
Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel) {



}
