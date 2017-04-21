object FInfo: TFInfo
  Left = 390
  Top = 165
  Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1095#1080#1090#1072#1090#1077#1083#1077
  ClientHeight = 451
  ClientWidth = 745
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Grid: TStringGrid
    Left = 16
    Top = 10
    Width = 713
    Height = 305
    BiDiMode = bdLeftToRight
    ColCount = 4
    DefaultColWidth = 177
    DefaultDrawing = False
    FixedCols = 0
    RowCount = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goThumbTracking]
    ParentBiDiMode = False
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    OnDrawCell = GridDrawCell
    OnSelectCell = GridSelectCell
    RowHeights = (
      24
      24)
  end
  object PProperties: TPanel
    Left = 16
    Top = 328
    Width = 713
    Height = 97
    TabOrder = 1
    object CAddBookName: TComboBox
      Left = 16
      Top = 16
      Width = 161
      Height = 21
      TabOrder = 0
    end
    object BAddBook: TButton
      Left = 213
      Top = 14
      Width = 119
      Height = 25
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1082#1085#1080#1075#1091
      TabOrder = 1
      OnClick = BAddBookClick
    end
    object BYellowPenalty: TButton
      Left = 360
      Top = 14
      Width = 161
      Height = 25
      Caption = #1042#1099#1076#1072#1090#1100' '#1078#1105#1083#1090#1091#1102' '#1082#1072#1088#1090#1086#1095#1082#1091
      TabOrder = 2
      OnClick = BYellowPenaltyClick
    end
    object BRedPenalty: TButton
      Left = 538
      Top = 14
      Width = 161
      Height = 25
      Caption = #1042#1099#1076#1072#1090#1100' '#1082#1088#1072#1089#1085#1091#1102' '#1082#1072#1088#1090#1086#1095#1082#1091
      TabOrder = 3
      OnClick = BRedPenaltyClick
    end
    object BAnnulPenalty: TButton
      Left = 360
      Top = 62
      Width = 161
      Height = 25
      Caption = #1040#1085#1085#1091#1083#1080#1088#1086#1074#1072#1090#1100' '#1096#1090#1088#1072#1092#1099
      TabOrder = 4
      OnClick = BAnnulPenaltyClick
    end
    object CDeleteBookName: TComboBox
      Left = 16
      Top = 64
      Width = 161
      Height = 21
      TabOrder = 5
    end
    object BDeleteBook: TButton
      Left = 213
      Top = 62
      Width = 119
      Height = 25
      Caption = #1059#1073#1088#1072#1090#1100' '#1082#1085#1080#1075#1091
      TabOrder = 6
      OnClick = BDeleteBookClick
    end
    object BBack: TButton
      Left = 538
      Top = 62
      Width = 161
      Height = 25
      Caption = #1053#1072#1079#1072#1076
      TabOrder = 7
      OnClick = BBackClick
    end
  end
end
