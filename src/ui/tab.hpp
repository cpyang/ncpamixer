#ifndef TAB_HPP_
#define TAB_HPP_

#include <map>
#include <string>
#include <vector>

#include "pa.hpp"

class Tab
{
public:
    bool has_volume;
    uint32_t selected_index;

    std::map<uint32_t, PaObject *> *object;
    std::map<uint32_t, PaObject *> *toggle;

    Tab()
    {
        object = nullptr;
        toggle = nullptr;
        selected_index = 0;
        selected_block = 0;
        total_blocks = 0;
        has_volume = true;
    }
    virtual ~Tab() = default;

    virtual void draw();
    void handleEvents(const char* const &event);
    bool handleMouse(int x, int y, int button);

    static void borderBox(int w, int h, int px, int py);
    static void selectBox(int w, int px, int py, bool selected);
    static void volumeBar(
        int w,
        int h,
        int px,
        int py,
        float vol,
        float peak
    );
    static uint32_t dropDown(
        int x,
        int y,
        std::map<uint32_t,
        PaObject *> objects,
        uint32_t current = 0,
        uint32_t width = 0,
        uint32_t height = 0
    );
    static uint32_t dropDown(
        int x,
        int y,
        std::map<uint32_t,
        std::string> objects,
        uint32_t current = 0,
        uint32_t width = 0,
        uint32_t height = 0
    );
    static uint32_t dropDown(
        int x,
        int y,
        std::vector<PaObjectAttribute *> attributes,
        uint32_t current = 0,
        uint32_t width = 0,
        uint32_t height = 0
    );
private:
    static void fillW(
        int w,
        int h,
        int offset_x,
        int offset_y,
        const char *str
    );
    static unsigned int getVolumeColor(int p);
    static unsigned int getBarColor(int p);

    int getBlockSize();
    bool handleMouseVolumeBarScroll(
        PaObject* item,
        int mousex,
        int mousey,
        int w,
        int h,
        int x,
        int y,
        int dir);
    bool handleMouseVolumeBar(
        PaObject* item,
        int mousex,
        int mousey,
        int w,
        int h,
        int x,
        int y
    );
    bool handleMouseDropDown(
        PaObject* item,
        int mousex,
        int mousey,
        int w,
        int h,
        int x,
        int y
    );
    bool handleMouseMoreUp(
        int mousex,
        int mousey,
        int w,
        int h,
        int x,
        int y
    );
    bool handleMouseMoreDown(
        int mousex,
        int mousey,
        int w,
        int h,
        int x,
        int y
    );
    void handleDropDown(PaObject* selected_pobj);

    int selected_block;
    int total_blocks;
};

#endif // TAB_HPP_
