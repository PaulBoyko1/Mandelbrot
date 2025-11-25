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

    if (m_State == State::CALCULATING) {
        for (int i = 0; i < m_pixel_size.y; i++) {
            for (int j = 0; j < m_pixel_size.x; j++) {
                m_vArray[j + i * m_pixel_size.x].position = { (float)j,(float)i };
            }
        }
    }

}
void ComplexPlane::zoomIn() {



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
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) {



}
Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousePixel) {


    
}
