object FormStorageEdit: TFormStorageEdit
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  ClientHeight = 246
  ClientWidth = 271
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 1
    Top = 1
    Width = 94
    Height = 13
    Caption = #1058#1080#1087' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
  end
  object Label2: TLabel
    Left = 1
    Top = 44
    Width = 88
    Height = 13
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077' '#1084#1086#1076#1077#1083#1080
  end
  object Label3: TLabel
    Left = 1
    Top = 85
    Width = 67
    Height = 13
    Caption = #1057#1077#1088#1080#1081#1085#1099#1081' '#8470
  end
  object Label4: TLabel
    Left = 0
    Top = 125
    Width = 85
    Height = 13
    Caption = #1048#1085#1074#1077#1085#1090#1072#1088#1085#1099#1081' '#8470
  end
  object Label5: TLabel
    Left = 0
    Top = 165
    Width = 72
    Height = 13
    Caption = #1044#1072#1090#1072' '#1074#1099#1087#1091#1089#1082#1072
  end
  object ComboBox1: TComboBox
    Left = 1
    Top = 20
    Width = 265
    Height = 21
    TabOrder = 0
    OnExit = ComboBox1Exit
  end
  object Edit2: TEdit
    Left = 0
    Top = 100
    Width = 265
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
  end
  object Edit3: TEdit
    Left = 0
    Top = 140
    Width = 265
    Height = 21
    TabOrder = 3
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 84
    Top = 165
    Width = 181
    Height = 21
    TabOrder = 4
    Text = 'Edit4'
  end
  object BitBtn1: TBitBtn
    Left = 92
    Top = 210
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    Glyph.Data = {
      DE010000424DDE01000000000000760000002800000024000000120000000100
      0400000000006801000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333333333333333330000333333333333333333333333F33333333333
      00003333344333333333333333388F3333333333000033334224333333333333
      338338F3333333330000333422224333333333333833338F3333333300003342
      222224333333333383333338F3333333000034222A22224333333338F338F333
      8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
      33333338F83338F338F33333000033A33333A222433333338333338F338F3333
      0000333333333A222433333333333338F338F33300003333333333A222433333
      333333338F338F33000033333333333A222433333333333338F338F300003333
      33333333A222433333333333338F338F00003333333333333A22433333333333
      3338F38F000033333333333333A223333333333333338F830000333333333333
      333A333333333333333338330000333333333333333333333333333333333333
      0000}
    NumGlyphs = 2
    TabOrder = 5
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 190
    Top = 210
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    Kind = bkCancel
    NumGlyphs = 2
    TabOrder = 6
  end
  object ComboBox2: TComboBox
    Left = 1
    Top = 61
    Width = 265
    Height = 21
    TabOrder = 1
    Text = 'ComboBox2'
  end
  object ADOQuery1: TADOQuery
    AutoCalcFields = False
    Connection = Form1.ADOConnection1
    Parameters = <>
    Left = 36
    Top = 200
  end
end
