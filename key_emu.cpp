#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int WaitTime, Indent, Check;
  int c = 0;
  int ERRORcount = 0;
  char *Layout;
  FILE *fp;
  char str[256];
  char *ptr;
  HANDLE hClip;
  char *pStr;

  fp = fopen("key_setting.txt", "r");

  for (int j = 0; j < 4; j++)
  {
    fgets(str, 256, fp);
    ++c;
    ptr = strtok(str, "=");
    ptr = strtok(NULL, "\n\r");
    switch (c)
    {
    case 1:
      WaitTime = atoi(ptr);
      break;
    case 2:
      Indent = atoi(ptr);
      break;
    case 3:
      Layout = ptr;
      break;
    }
  }

  OpenClipboard(NULL);

  hClip = GetClipboardData(CF_TEXT);
  if (hClip != NULL)
  {

    pStr = (char *)GlobalLock(hClip);

    printf("Input date:\n\n%s\n\n", pStr);

    GlobalUnlock(hClip);
  }
  CloseClipboard();

  puts("Waiting...");

  for (int i = 5; i > 0; i--)
  {
    printf("%d", i);
    Sleep(1000);
  }
  printf("\nStart!");
  Sleep(1000);

  puts("\n\nTyping, Don't touch the PC\n");

  const unsigned char *p = (const unsigned char *)(pStr);

  if (!strcmp(Layout, "EN_US"))
  {
    for (; *p; ++p)
    {
      if ('a' <= *p && 'z' >= *p)
      {
        keybd_event(*p - 32, 0, 0, 0);
        keybd_event(*p - 32, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('A' <= *p && 'Z' >= *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(*p, 0, 0, 0);
        keybd_event(*p, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('0' <= *p && '9' >= *p)
      {
        keybd_event(*p, 0, 0, 0);
        keybd_event(*p, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (';' == *p)
      {
        keybd_event(0xBA, 0, 0, 0);
        keybd_event(0xBA, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (':' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBA, 0, 0, 0);
        keybd_event(0xBA, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('=' == *p)
      {
        keybd_event(0xBB, 0, 0, 0);
        keybd_event(0xBB, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('+' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBB, 0, 0, 0);
        keybd_event(0xBB, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (',' == *p)
      {
        keybd_event(0xBC, 0, 0, 0);
        keybd_event(0xBC, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('<' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBC, 0, 0, 0);
        keybd_event(0xBC, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('-' == *p)
      {
        keybd_event(0xBD, 0, 0, 0);
        keybd_event(0xBD, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('_' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBD, 0, 0, 0);
        keybd_event(0xBD, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('.' == *p)
      {
        keybd_event(0xBE, 0, 0, 0);
        keybd_event(0xBE, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('>' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBE, 0, 0, 0);
        keybd_event(0xBE, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('/' == *p)
      {
        keybd_event(0xBF, 0, 0, 0);
        keybd_event(0xBF, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('?' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBF, 0, 0, 0);
        keybd_event(0xBF, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('`' == *p)
      {
        keybd_event(0xC0, 0, 0, 0);
        keybd_event(0xC0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('~' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xC0, 0, 0, 0);
        keybd_event(0xC0, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('[' == *p)
      {
        keybd_event(0xDB, 0, 0, 0);
        keybd_event(0xDB, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('{' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xDB, 0, 0, 0);
        keybd_event(0xDB, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('\\' == *p)
      {
        keybd_event(0xDC, 0, 0, 0);
        keybd_event(0xDC, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('|' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xDC, 0, 0, 0);
        keybd_event(0xDC, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (']' == *p)
      {
        keybd_event(0xDD, 0, 0, 0);
        keybd_event(0xDD, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('}' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xDD, 0, 0, 0);
        keybd_event(0xDD, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('!' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x31, 0, 0, 0);
        keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('@' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x32, 0, 0, 0);
        keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('#' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x33, 0, 0, 0);
        keybd_event(0x33, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('$' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x34, 0, 0, 0);
        keybd_event(0x34, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('%' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x35, 0, 0, 0);
        keybd_event(0x35, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('^' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x36, 0, 0, 0);
        keybd_event(0x36, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('&' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x37, 0, 0, 0);
        keybd_event(0x37, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('*' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x38, 0, 0, 0);
        keybd_event(0x38, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('(' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x39, 0, 0, 0);
        keybd_event(0x39, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (')' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x30, 0, 0, 0);
        keybd_event(0x30, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('\'' == *p)
      {
        keybd_event(0xDE, 0, 0, 0);
        keybd_event(0xDE, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('\"' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xDE, 0, 0, 0);
        keybd_event(0xDE, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ((' ' == *p) && (Indent == 1))
      {
        keybd_event(0x20, 0, 0, 0);
        keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (' ' == *p && (Indent == 0))
      {
        ++p;
        if (' ' != *p)
        {
          keybd_event(0x20, 0, 0, 0);
          keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);
          --p;
        }
      }
      else if ('\n' == *p || '\r' == *p)
      {
        keybd_event(0x0d, 0, 0, 0);
        keybd_event(0x0d, 0, KEYEVENTF_KEYUP, 0);
        ++p;
      }
      else
      {
        printf("ERROR ?byte:%x\n", *p);
        ++ERRORcount;
      }
      Sleep(WaitTime);
    }
  }
  else if (!strcmp(Layout, "JP"))
  {
    for (; *p; ++p)
    {
      if ('a' <= *p && 'z' >= *p)
      {
        keybd_event(*p - 32, 0, 0, 0);
        keybd_event(*p - 32, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('A' <= *p && 'Z' >= *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(*p, 0, 0, 0);
        keybd_event(*p, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('0' <= *p && '9' >= *p)
      {
        keybd_event(*p, 0, 0, 0);
        keybd_event(*p, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (';' == *p)
      {
        keybd_event(0xBB, 0, 0, 0);
        keybd_event(0xBB, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (':' == *p)
      {
        keybd_event(0xBA, 0, 0, 0);
        keybd_event(0xBA, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('=' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBD, 0, 0, 0);
        keybd_event(0xBD, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('+' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBB, 0, 0, 0);
        keybd_event(0xBB, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (',' == *p)
      {
        keybd_event(0xBC, 0, 0, 0);
        keybd_event(0xBC, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('<' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBC, 0, 0, 0);
        keybd_event(0xBC, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('-' == *p)
      {
        keybd_event(0xBD, 0, 0, 0);
        keybd_event(0xBD, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('_' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xE2, 0, 0, 0);
        keybd_event(0xE2, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('.' == *p)
      {
        keybd_event(0xBE, 0, 0, 0);
        keybd_event(0xBE, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('>' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBE, 0, 0, 0);
        keybd_event(0xBE, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('/' == *p)
      {
        keybd_event(0xBF, 0, 0, 0);
        keybd_event(0xBF, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('?' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBF, 0, 0, 0);
        keybd_event(0xBF, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('`' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xC0, 0, 0, 0);
        keybd_event(0xC0, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('~' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xDE, 0, 0, 0);
        keybd_event(0xDE, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('[' == *p)
      {
        keybd_event(0xDB, 0, 0, 0);
        keybd_event(0xDB, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('{' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xDB, 0, 0, 0);
        keybd_event(0xDB, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('\\' == *p)
      {
        keybd_event(0xE2, 0, 0, 0);
        keybd_event(0xE2, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('|' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xDC, 0, 0, 0);
        keybd_event(0xDC, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (']' == *p)
      {
        keybd_event(0xDD, 0, 0, 0);
        keybd_event(0xDD, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('}' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xDD, 0, 0, 0);
        keybd_event(0xDD, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('!' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x31, 0, 0, 0);
        keybd_event(0x31, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('@' == *p)
      {
        keybd_event(0xC0, 0, 0, 0);
        keybd_event(0xC0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('#' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x33, 0, 0, 0);
        keybd_event(0x33, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('$' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x34, 0, 0, 0);
        keybd_event(0x34, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('%' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x35, 0, 0, 0);
        keybd_event(0x35, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('^' == *p)
      {
        keybd_event(0xDE, 0, 0, 0);
        keybd_event(0xBB, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('&' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x36, 0, 0, 0);
        keybd_event(0x36, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('*' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0xBA, 0, 0, 0);
        keybd_event(0xBA, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('(' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x38, 0, 0, 0);
        keybd_event(0x38, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (')' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x39, 0, 0, 0);
        keybd_event(0x39, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('\'' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x37, 0, 0, 0);
        keybd_event(0x37, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if ('\"' == *p)
      {
        keybd_event(0xA0, 0, 0, 0);
        keybd_event(0x32, 0, 0, 0);
        keybd_event(0x32, 0, KEYEVENTF_KEYUP, 0);
        keybd_event(0xA0, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (' ' == *p && (Indent == 1))
      {
        keybd_event(0x20, 0, 0, 0);
        keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);
      }
      else if (' ' == *p && (Indent == 0))
      {
        ++p;
        if (' ' != *p)
        {
          keybd_event(0x20, 0, 0, 0);
          keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);
          --p;
        }
      }
      else if ('\n' == *p || '\r' == *p)
      {
        keybd_event(0x0d, 0, 0, 0);
        keybd_event(0x0d, 0, KEYEVENTF_KEYUP, 0);
        ++p;
      }
      else
      {
        printf("ERROR ?byte:%x\n", *p);
        ++ERRORcount;
      }
      Sleep(WaitTime);
    }
  }
  else
  {
    puts("Check Layout Setting");
    return 1;
  }

  printf("\nERROR = %u", ERRORcount);
  puts("\nComplete!");
  Sleep(1000);

  return 0;
}
