﻿object formAlgСircle: TformAlgСircle
  Left = 488
  Top = 110
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #1048#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077' '#1072#1083#1075#1086#1088#1080#1090#1084#1086#1074' '#1087#1086#1089#1090#1088#1086#1077#1085#1080#1103' '#1086#1082#1088#1091#1078#1085#1086#1089#1090#1077#1081' '#1080' '#1101#1083#1083#1080#1087#1089#1086#1074
  ClientHeight = 500
  ClientWidth = 716
  Color = clLime
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 18
  object Image1: TImage
    Left = 5
    Top = 5
    Width = 501
    Height = 351
  end
  object Label5: TLabel
    Left = 5
    Top = 357
    Width = 8
    Height = 18
    Caption = '0'
  end
  object Label6: TLabel
    Left = 482
    Top = 357
    Width = 24
    Height = 18
    Caption = '500'
  end
  object Label7: TLabel
    Left = 507
    Top = 5
    Width = 8
    Height = 18
    Caption = '0'
  end
  object Label8: TLabel
    Left = 507
    Top = 338
    Width = 24
    Height = 18
    Caption = '350'
  end
  object Label9: TLabel
    Left = 507
    Top = 37
    Width = 10
    Height = 18
    Caption = 'Y'
  end
  object Label10: TLabel
    Left = 450
    Top = 357
    Width = 9
    Height = 18
    Caption = 'X'
  end
  object Label16: TLabel
    Left = 531
    Top = 252
    Width = 155
    Height = 18
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1094#1074#1077#1090' '#1083#1080#1085#1080#1080':'
  end
  object Label17: TLabel
    Left = 359
    Top = 424
    Width = 169
    Height = 18
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1094#1074#1077#1090' '#1079#1072#1083#1080#1074#1082#1080':'
  end
  object rgrChooseAlg: TRadioGroup
    Left = 19
    Top = 368
    Width = 334
    Height = 124
    Caption = #1048#1089#1087#1086#1083#1100#1079#1091#1077#1090#1089#1103' '#1072#1083#1075#1086#1088#1080#1090#1084' '#1087#1086#1089#1090#1088#1086#1077#1085#1080#1103' '#1101#1083#1083#1080#1087#1089#1072':'
    ItemIndex = 0
    Items.Strings = (
      #1055#1086' '#1082#1072#1085#1086#1085#1080#1095#1077#1089#1082#1086#1084#1091' '#1091#1088#1072#1074#1085#1077#1085#1080#1102
      #1055#1086' '#1087#1072#1088#1072#1084#1077#1090#1088#1080#1095#1077#1089#1082#1086#1084#1091' '#1091#1088#1072#1074#1085#1077#1085#1080#1102
      #1052#1077#1090#1086#1076' '#1089#1088#1077#1076#1085#1077#1081' '#1090#1086#1095#1082#1080
      #1040#1083#1075#1086#1088#1080#1090#1084' '#1041#1088#1077#1079#1077#1085#1093#1077#1084#1072
      #1057#1090#1072#1085#1076#1072#1088#1090#1085#1099#1077' '#1084#1077#1090#1086#1076#1099' '#1089#1088#1077#1076#1099)
    TabOrder = 0
  end
  object gpbCenter: TGroupBox
    Left = 533
    Top = 5
    Width = 106
    Height = 84
    Caption = #1062#1077#1085#1090#1088
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 9
      Height = 18
      Caption = 'X'
    end
    object Label2: TLabel
      Left = 8
      Top = 56
      Width = 10
      Height = 18
      Caption = 'Y'
    end
    object edtXC: TEdit
      Left = 23
      Top = 21
      Width = 74
      Height = 26
      TabOrder = 0
    end
    object edtYC: TEdit
      Left = 23
      Top = 53
      Width = 74
      Height = 26
      TabOrder = 1
    end
  end
  object gpbEndPoint: TGroupBox
    Left = 533
    Top = 90
    Width = 106
    Height = 85
    Caption = #1054#1089#1080
    TabOrder = 2
    object Label3: TLabel
      Left = 8
      Top = 24
      Width = 9
      Height = 18
      Caption = 'A'
    end
    object Label4: TLabel
      Left = 8
      Top = 56
      Width = 9
      Height = 18
      Caption = 'B'
    end
    object edtXAxis: TEdit
      Left = 23
      Top = 21
      Width = 74
      Height = 26
      NumbersOnly = True
      TabOrder = 0
      OnChange = edtXAxisChange
    end
    object edtYAxis: TEdit
      Left = 23
      Top = 53
      Width = 74
      Height = 26
      NumbersOnly = True
      TabOrder = 1
      OnChange = edtYAxisChange
    end
  end
  object btnDrawEllipse: TButton
    Left = 531
    Top = 205
    Width = 147
    Height = 41
    Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' '#1101#1083#1083#1080#1087#1089
    TabOrder = 3
    OnClick = btnDrawEllipseClick
  end
  object chbSetTimer: TCheckBox
    Left = 359
    Top = 475
    Width = 192
    Height = 17
    Caption = #1047#1072#1084#1077#1088#1080#1090#1100' '#1074#1088#1077#1084#1103
    TabOrder = 4
  end
  object btnClearCanvas: TButton
    Left = 359
    Top = 381
    Width = 169
    Height = 37
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1087#1086#1083#1086#1090#1085#1086
    TabOrder = 5
    OnClick = btnClearCanvasClick
  end
  object gpbSunTest: TGroupBox
    Left = 557
    Top = 297
    Width = 130
    Height = 195
    Caption = #1051#1091#1095#1077#1074#1086#1081' '#1090#1077#1089#1090
    TabOrder = 6
    object Label11: TLabel
      Left = 8
      Top = 24
      Width = 17
      Height = 18
      Caption = 'A0'
    end
    object Label12: TLabel
      Left = 8
      Top = 56
      Width = 17
      Height = 18
      Caption = 'B0'
    end
    object Label13: TLabel
      Left = 8
      Top = 88
      Width = 17
      Height = 18
      Caption = 'dA'
    end
    object Label14: TLabel
      Left = 8
      Top = 120
      Width = 46
      Height = 18
      Caption = #1050#1086#1083'-'#1074#1086
    end
    object edtXSun: TEdit
      Left = 36
      Top = 21
      Width = 74
      Height = 26
      TabOrder = 0
    end
    object edtYSun: TEdit
      Left = 36
      Top = 53
      Width = 74
      Height = 26
      TabOrder = 1
    end
    object edtRSun: TEdit
      Left = 36
      Top = 85
      Width = 74
      Height = 26
      TabOrder = 2
    end
    object edtAngleStep: TEdit
      Left = 65
      Top = 117
      Width = 45
      Height = 26
      TabOrder = 3
    end
    object btnBuildSun: TButton
      Left = 16
      Top = 149
      Width = 105
      Height = 43
      Caption = #1055#1086#1089#1090#1088#1086#1080#1090#1100' "'#1089#1087#1077#1082#1090#1088'"'
      TabOrder = 4
      WordWrap = True
      OnClick = btnBuildSunClick
    end
  end
  object clbLineColor: TColorBox
    Left = 531
    Top = 272
    Width = 145
    Height = 22
    Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbPrettyNames, cbCustomColors]
    TabOrder = 7
    OnChange = clbLineColorChange
  end
  object clbBgndColor: TColorBox
    Left = 382
    Top = 448
    Width = 145
    Height = 22
    DefaultColorColor = clWhite
    NoneColorColor = clWhite
    Selected = clWhite
    Style = [cbStandardColors, cbExtendedColors, cbSystemColors, cbPrettyNames, cbCustomColors]
    TabOrder = 8
    OnChange = clbBgndColorChange
  end
  object chbEqAxis: TCheckBox
    Left = 536
    Top = 184
    Width = 172
    Height = 17
    Caption = #1056#1080#1089#1086#1074#1072#1090#1100' '#1086#1082#1088#1091#1078#1085#1086#1089#1090#1100
    TabOrder = 9
    OnClick = chbEqAxisClick
  end
end
