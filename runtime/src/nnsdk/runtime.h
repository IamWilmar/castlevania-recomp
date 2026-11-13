#pragma once
// Servicios internos de libnnsdk.so compartidos entre módulos (os, libc…).

#include <string>

#include "nnsdk/host.h"

namespace nnsdk {

const NnsdkHost& host();

// Cada hilo nuevo del juego avisa al loader (pila alternativa para el crash handler).
void on_thread_start();

// Ruta en el sistema de un archivo del juego ("rom:/movie/a.webm" -> su sitio en la SD); vacía sin punto de montaje.
std::string fs_host_path(const char* path);

// Modo TV: con <datos>/modo_tv al abrir el juego, la consola dice estar en la base (oe: modo Console y rendimiento
// Boost) y el mando es un mando Pro en el hueco No1 (en la base el portátil no cuenta como mando). Se decide una vez
// por sesión: el panel lo cambia para el próximo arranque.
bool tv_mode();

}  // namespace nnsdk
