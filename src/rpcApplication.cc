#include "rpcApplication.h"

#include <cstdlib>
#include <iostream>
#include <unistd.h>

rpcApplication &rpcApplication::instance() {
  static rpcApplication rpcApp;
  return rpcApp;
}

void showArgsHelp() {
  std::cout << "format: command -i <configfile>" << std::endl;
}

void rpcApplication::init(int argc, char **argv) {
  if (argc < 2) {
    showArgsHelp();
    exit(EXIT_FAILURE);
  }

  int c = 0;
  std::string s;
  while ((c = getopt(argc, argv, "i:")) != -1) {
    switch (c) {
    case 'i':
      s = optarg;
      break;
    case '?':
      showArgsHelp();
      exit(EXIT_FAILURE);
    case ':':
      showArgsHelp();
      exit(EXIT_FAILURE);
    default:
      break;
    }
  }

  // TODO:config
}