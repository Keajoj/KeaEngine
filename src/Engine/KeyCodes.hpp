#ifndef KEA_ENGINE_KEYCODES_HPP
#define KEA_ENGINE_KEYCODES_HPP

#include "glfw/glfw3.h"

namespace Kea
{

/// For now, this is an obviously thin wrapper for GLFW's key codes. We may
/// modify this enum class to support other inputs in the future.
enum class KeyCode
{
    SPACE = GLFW_KEY_SPACE,
    APOSTROPHE = GLFW_KEY_APOSTROPHE,
    COMMA = GLFW_KEY_COMMA,
    MINUS = GLFW_KEY_MINUS,
    PERIOD = GLFW_KEY_PERIOD,
    SLASH = GLFW_KEY_SLASH,
    D0 = GLFW_KEY_0,
    D1 = GLFW_KEY_1,
    D2 = GLFW_KEY_2,
    D3 = GLFW_KEY_3,
    D4 = GLFW_KEY_4,
    D5 = GLFW_KEY_5,
    D6 = GLFW_KEY_6,
    D7 = GLFW_KEY_7,
    D8 = GLFW_KEY_8,
    D9 = GLFW_KEY_9,
    SEMICOLON = GLFW_KEY_SEMICOLON,
    EQUAL = GLFW_KEY_EQUAL,
    A = GLFW_KEY_A,
    B = GLFW_KEY_B,
    C = GLFW_KEY_C,
    D = GLFW_KEY_D,
    E = GLFW_KEY_E,
    F = GLFW_KEY_F,
    G = GLFW_KEY_G,
    H = GLFW_KEY_H,
    I = GLFW_KEY_I,
    J = GLFW_KEY_J,
    K = GLFW_KEY_K,
    L = GLFW_KEY_L,
    M = GLFW_KEY_M,
    N = GLFW_KEY_N,
    O = GLFW_KEY_O,
    P = GLFW_KEY_P,
    Q = GLFW_KEY_Q,
    R = GLFW_KEY_R,
    S = GLFW_KEY_S,
    T = GLFW_KEY_T,
    U = GLFW_KEY_U,
    V = GLFW_KEY_V,
    W = GLFW_KEY_W,
    X = GLFW_KEY_X,
    Y = GLFW_KEY_Y,
    Z = GLFW_KEY_Z,
    LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET,
    BACKSLASH = GLFW_KEY_BACKSLASH,
    RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET,
    GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT,
    WORLD_1 = GLFW_KEY_WORLD_1,
    WORLD_2 = GLFW_KEY_WORLD_2,
    ESCAPE = GLFW_KEY_ESCAPE,
    ENTER = GLFW_KEY_ENTER,
    TAB = GLFW_KEY_TAB,
    BACKSPACE = GLFW_KEY_BACKSPACE,
    INSERT = GLFW_KEY_INSERT,
    DELETE = GLFW_KEY_DELETE,
    RIGHT_ARROW = GLFW_KEY_RIGHT,
    LEFT_ARROW = GLFW_KEY_LEFT,
    DOWN_ARROW = GLFW_KEY_DOWN,
    UP_ARROW = GLFW_KEY_UP,
    PAGE_UP = GLFW_KEY_PAGE_UP,
    PAGE_DOWN = GLFW_KEY_PAGE_DOWN,
    HOME = GLFW_KEY_HOME,
    END = GLFW_KEY_END,
    CAPS_LOCK = GLFW_KEY_CAPS_LOCK,
    SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK,
    NUM_LOCK = GLFW_KEY_NUM_LOCK,
    PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN,
    PAUSE = GLFW_KEY_PAUSE,
    F1 = GLFW_KEY_F1,
    F2 = GLFW_KEY_F2,
    F3 = GLFW_KEY_F3,
    F4 = GLFW_KEY_F4,
    F5 = GLFW_KEY_F5,
    F6 = GLFW_KEY_F6,
    F7 = GLFW_KEY_F7,
    F8 = GLFW_KEY_F8,
    F9 = GLFW_KEY_F9,
    F10 = GLFW_KEY_F10,
    F11 = GLFW_KEY_F11,
    F12 = GLFW_KEY_F12,
    F13 = GLFW_KEY_F13,
    F14 = GLFW_KEY_F14,
    F15 = GLFW_KEY_F15,
    F16 = GLFW_KEY_F16,
    F17 = GLFW_KEY_F17,
    F18 = GLFW_KEY_F18,
    F19 = GLFW_KEY_F19,
    F20 = GLFW_KEY_F20,
    F21 = GLFW_KEY_F21,
    F22 = GLFW_KEY_F22,
    F23 = GLFW_KEY_F23,
    F24 = GLFW_KEY_F24,
    F25 = GLFW_KEY_F25,
    NUMPAD_0 = GLFW_KEY_KP_0,
    NUMPAD_1 = GLFW_KEY_KP_1,
    NUMPAD_2 = GLFW_KEY_KP_2,
    NUMPAD_3 = GLFW_KEY_KP_3,
    NUMPAD_4 = GLFW_KEY_KP_4,
    NUMPAD_5 = GLFW_KEY_KP_5,
    NUMPAD_6 = GLFW_KEY_KP_6,
    NUMPAD_7 = GLFW_KEY_KP_7,
    NUMPAD_8 = GLFW_KEY_KP_8,
    NUMPAD_9 = GLFW_KEY_KP_9,
    NUMPAD_DECIMAL = GLFW_KEY_KP_DECIMAL,
    NUMPAD_DIVIDE = GLFW_KEY_KP_DIVIDE,
    NUMPAD_MULTIPLY = GLFW_KEY_KP_MULTIPLY,
    NUMPAD_SUBTRACT = GLFW_KEY_KP_SUBTRACT,
    NUMPAD_ADD = GLFW_KEY_KP_ADD,
    NUMPAD_ENTER = GLFW_KEY_KP_ENTER,
    NUMPAD_EQUAL = GLFW_KEY_KP_EQUAL,
    LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
    LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL,
    LEFT_ALT = GLFW_KEY_LEFT_ALT,
    LEFT_SUPER = GLFW_KEY_LEFT_SUPER,
    RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
    RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
    RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
    RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER,
    MENU = GLFW_KEY_MENU,
    LAST = GLFW_KEY_LAST,
};

inline const char* ToString(KeyCode key)
{
    switch (key)
    {
    case KeyCode::SPACE:
        return "SPACE";
    case KeyCode::APOSTROPHE:
        return "APOSTROPHE";
    case KeyCode::COMMA:
        return "COMMA";
    case KeyCode::MINUS:
        return "MINUS";
    case KeyCode::PERIOD:
        return "PERIOD";
    case KeyCode::SLASH:
        return "SLASH";
    case KeyCode::D0:
        return "D0";
    case KeyCode::D1:
        return "D1";
    case KeyCode::D2:
        return "D2";
    case KeyCode::D3:
        return "D3";
    case KeyCode::D4:
        return "D4";
    case KeyCode::D5:
        return "D5";
    case KeyCode::D6:
        return "D6";
    case KeyCode::D7:
        return "D7";
    case KeyCode::D8:
        return "D8";
    case KeyCode::D9:
        return "D9";
    case KeyCode::SEMICOLON:
        return "SEMICOLON";
    case KeyCode::EQUAL:
        return "EQUAL";
    case KeyCode::A:
        return "A";
    case KeyCode::B:
        return "B";
    case KeyCode::C:
        return "C";
    case KeyCode::D:
        return "D";
    case KeyCode::E:
        return "E";
    case KeyCode::F:
        return "F";
    case KeyCode::G:
        return "G";
    case KeyCode::H:
        return "H";
    case KeyCode::I:
        return "I";
    case KeyCode::J:
        return "J";
    case KeyCode::K:
        return "K";
    case KeyCode::L:
        return "L";
    case KeyCode::M:
        return "M";
    case KeyCode::N:
        return "N";
    case KeyCode::O:
        return "O";
    case KeyCode::P:
        return "P";
    case KeyCode::Q:
        return "Q";
    case KeyCode::R:
        return "R";
    case KeyCode::S:
        return "S";
    case KeyCode::T:
        return "T";
    case KeyCode::U:
        return "U";
    case KeyCode::V:
        return "V";
    case KeyCode::W:
        return "W";
    case KeyCode::X:
        return "X";
    case KeyCode::Y:
        return "Y";
    case KeyCode::Z:
        return "Z";
    case KeyCode::LEFT_BRACKET:
        return "LEFT_BRACKET";
    case KeyCode::BACKSLASH:
        return "BACKSLASH";
    case KeyCode::RIGHT_BRACKET:
        return "RIGHT_BRACKET";
    case KeyCode::GRAVE_ACCENT:
        return "GRAVE_ACCENT";
    case KeyCode::WORLD_1:
        return "WORLD_1";
    case KeyCode::WORLD_2:
        return "WORLD_2";
    case KeyCode::ESCAPE:
        return "ESCAPE";
    case KeyCode::ENTER:
        return "ENTER";
    case KeyCode::TAB:
        return "TAB";
    case KeyCode::BACKSPACE:
        return "BACKSPACE";
    case KeyCode::INSERT:
        return "INSERT";
    case KeyCode::DELETE:
        return "DELETE";
    case KeyCode::RIGHT_ARROW:
        return "RIGHT_ARROW";
    case KeyCode::LEFT_ARROW:
        return "LEFT_ARROW";
    case KeyCode::DOWN_ARROW:
        return "DOWN_ARROW";
    case KeyCode::UP_ARROW:
        return "UP_ARROW";
    case KeyCode::PAGE_UP:
        return "PAGE_UP";
    case KeyCode::PAGE_DOWN:
        return "PAGE_DOWN";
    case KeyCode::HOME:
        return "HOME";
    case KeyCode::END:
        return "END";
    case KeyCode::CAPS_LOCK:
        return "CAPS_LOCK";
    case KeyCode::SCROLL_LOCK:
        return "SCROLL_LOCK";
    case KeyCode::NUM_LOCK:
        return "NUM_LOCK";
    case KeyCode::PRINT_SCREEN:
        return "PRINT_SCREEN";
    case KeyCode::PAUSE:
        return "PAUSE";
    case KeyCode::F1:
        return "F1";
    case KeyCode::F2:
        return "F2";
    case KeyCode::F3:
        return "F3";
    case KeyCode::F4:
        return "F4";
    case KeyCode::F5:
        return "F5";
    case KeyCode::F6:
        return "F6";
    case KeyCode::F7:
        return "F7";
    case KeyCode::F8:
        return "F8";
    case KeyCode::F9:
        return "F9";
    case KeyCode::F10:
        return "F10";
    case KeyCode::F11:
        return "F11";
    case KeyCode::F12:
        return "F12";
    case KeyCode::F13:
        return "F13";
    case KeyCode::F14:
        return "F14";
    case KeyCode::F15:
        return "F15";
    case KeyCode::F16:
        return "F16";
    case KeyCode::F17:
        return "F17";
    case KeyCode::F18:
        return "F18";
    case KeyCode::F19:
        return "F19";
    case KeyCode::F20:
        return "F20";
    case KeyCode::F21:
        return "F21";
    case KeyCode::F22:
        return "F22";
    case KeyCode::F23:
        return "F23";
    case KeyCode::F24:
        return "F24";
    case KeyCode::F25:
        return "F25";
    case KeyCode::NUMPAD_0:
        return "NUMPAD_0";
    case KeyCode::NUMPAD_1:
        return "NUMPAD_1";
    case KeyCode::NUMPAD_2:
        return "NUMPAD_2";
    case KeyCode::NUMPAD_3:
        return "NUMPAD_3";
    case KeyCode::NUMPAD_4:
        return "NUMPAD_4";
    case KeyCode::NUMPAD_5:
        return "NUMPAD_5";
    case KeyCode::NUMPAD_6:
        return "NUMPAD_6";
    case KeyCode::NUMPAD_7:
        return "NUMPAD_7";
    case KeyCode::NUMPAD_8:
        return "NUMPAD_8";
    case KeyCode::NUMPAD_9:
        return "NUMPAD_9";
    case KeyCode::NUMPAD_DECIMAL:
        return "NUMPAD_DECIMAL";
    case KeyCode::NUMPAD_DIVIDE:
        return "NUMPAD_DIVIDE";
    case KeyCode::NUMPAD_MULTIPLY:
        return "NUMPAD_MULTIPLY";
    case KeyCode::NUMPAD_SUBTRACT:
        return "NUMPAD_SUBTRACT";
    case KeyCode::NUMPAD_ADD:
        return "NUMPAD_ADD";
    case KeyCode::NUMPAD_ENTER:
        return "NUMPAD_ENTER";
    case KeyCode::NUMPAD_EQUAL:
        return "NUMPAD_EQUAL";
    case KeyCode::LEFT_SHIFT:
        return "LEFT_SHIFT";
    case KeyCode::LEFT_CONTROL:
        return "LEFT_CONTROL";
    case KeyCode::LEFT_ALT:
        return "LEFT_ALT";
    case KeyCode::LEFT_SUPER:
        return "LEFT_SUPER";
    case KeyCode::RIGHT_SHIFT:
        return "RIGHT_SHIFT";
    case KeyCode::RIGHT_CONTROL:
        return "RIGHT_CONTROL";
    case KeyCode::RIGHT_ALT:
        return "RIGHT_ALT";
    case KeyCode::RIGHT_SUPER:
        return "RIGHT_SUPER";
    case KeyCode::MENU:
        return "MENU";
    default:
        return "UNKNOWN_KEY_CODE";
    }
}
} // namespace Kea

#endif /* KEA_ENGINE_KEYCODES_HPP */
