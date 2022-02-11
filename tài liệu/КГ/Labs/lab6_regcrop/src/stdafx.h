// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
#pragma once

// TODO: reference additional headers your program requires here


#define CONVERT_NUMBER System::Globalization::NumberStyles::Number, System::Globalization::NumberFormatInfo::CurrentInfo

#define DEBUGPRINT(s, ...) System::Windows::Forms::MessageBox::Show(System::String::Format(s, __VA_ARGS__))

#define DABS(x) ((x) < 0 ? -(x) : (x))

#define SHOW_ERROR(s, ...) System::Windows::Forms::MessageBox::Show(System::String::Format(s, __VA_ARGS__), "������", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
#define SHOW_WARNING(s, ...) System::Windows::Forms::MessageBox::Show(System::String::Format(s, __VA_ARGS__), "��������������", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
#define SHOW_INFO(s, ...) System::Windows::Forms::MessageBox::Show(System::String::Format(s, __VA_ARGS__), "����������", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);