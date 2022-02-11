// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

// TODO: reference additional headers your program requires here

#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#define DEBUGPRINT(s, ...) System::Windows::Forms::MessageBox::Show(System::String::Format(s, __VA_ARGS__))
#define MAX(A, B) ((A)<(B)) ? (B) : (A)