object FMain: TFMain
  Left = 585
  Top = 274
  Caption = #1041#1080#1073#1083#1080#1086#1090#1077#1082#1072' '#1082#1072#1092#1077#1076#1088#1099
  ClientHeight = 293
  ClientWidth = 222
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PReaders: TPanel
    Left = 24
    Top = 15
    Width = 177
    Height = 250
    TabOrder = 1
    Visible = False
    object BReadersAddReader: TButton
      Left = 11
      Top = 16
      Width = 158
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1095#1080#1090#1072#1090#1077#1083#1103
      TabOrder = 0
    end
    object BReadersEditing: TButton
      Left = 11
      Top = 55
      Width = 158
      Height = 25
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1102
      TabOrder = 1
    end
    object BReadersBack: TButton
      Left = 48
      Top = 185
      Width = 75
      Height = 25
      Caption = #1053#1072#1079#1072#1076
      TabOrder = 2
    end
    object BReadersPenalty: TButton
      Left = 11
      Top = 138
      Width = 158
      Height = 25
      Caption = #1042#1099#1076#1072#1095#1072' '#1096#1090#1088#1072#1092#1086#1074
      TabOrder = 3
    end
    object BReadersSearch: TButton
      Left = 11
      Top = 98
      Width = 158
      Height = 25
      Caption = #1055#1086#1080#1089#1082' '#1095#1080#1090#1072#1090#1077#1083#1077#1081
      TabOrder = 4
    end
  end
  object PBuy: TPanel
    Left = 24
    Top = 15
    Width = 177
    Height = 250
    TabOrder = 2
    Visible = False
    object BBuyNew: TButton
      Left = 16
      Top = 48
      Width = 145
      Height = 25
      Caption = #1050#1091#1087#1080#1090#1100' '#1085#1086#1074#1091#1102
      TabOrder = 0
      OnClick = BBuyNewClick
    end
    object BBuyOld: TButton
      Left = 16
      Top = 110
      Width = 145
      Height = 25
      Caption = #1050#1091#1087#1080#1090#1100' '#1091#1078#1077' '#1080#1084#1077#1102#1097#1091#1102#1089#1103
      TabOrder = 1
    end
    object BBuyBack: TButton
      Left = 16
      Top = 172
      Width = 145
      Height = 25
      Caption = #1053#1072#1079#1072#1076
      TabOrder = 2
    end
  end
  object PBuyNew: TPanel
    Left = 24
    Top = 15
    Width = 177
    Height = 250
    TabOrder = 3
    Visible = False
    object BBuyNewBack: TButton
      Left = 48
      Top = 203
      Width = 75
      Height = 25
      Caption = #1053#1072#1079#1072#1076
      TabOrder = 0
      OnClick = BBuyNewBackClick
    end
  end
  object PMain: TPanel
    Left = 24
    Top = 15
    Width = 177
    Height = 250
    TabOrder = 0
    object BMainBook: TButton
      Left = 16
      Top = 24
      Width = 137
      Height = 25
      Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1082#1085#1080#1075#1072#1084#1080
      TabOrder = 0
      OnClick = BMainBookClick
    end
    object BMainReaders: TButton
      Left = 16
      Top = 79
      Width = 137
      Height = 25
      Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1095#1080#1090#1072#1090#1077#1083#1103#1084#1080
      TabOrder = 1
      OnClick = BMainReadersClick
    end
    object BMainInfo: TButton
      Left = 16
      Top = 141
      Width = 137
      Height = 25
      Caption = #1054#1090#1095#1105#1090#1085#1086#1089#1090#1100
      TabOrder = 2
      OnClick = BMainInfoClick
    end
    object BMainExit: TButton
      Left = 16
      Top = 200
      Width = 137
      Height = 25
      Caption = #1042#1099#1093#1086#1076
      TabOrder = 3
      OnClick = BMainExitClick
    end
  end
end
