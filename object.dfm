object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 155
  ClientWidth = 249
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 4
    Top = 3
    Width = 108
    Height = 13
    Caption = #1051#1086#1082#1072#1083#1100#1085#1099#1081' IP-'#1072#1076#1088#1077#1089':'
  end
  object Label2: TLabel
    Left = 118
    Top = 3
    Width = 68
    Height = 13
    Caption = #1057#1077#1090#1077#1074#1086#1077' '#1080#1084#1103':'
  end
  object Label3: TLabel
    Left = 4
    Top = 41
    Width = 59
    Height = 13
    Caption = #1055#1089#1077#1074#1076#1086#1085#1080#1084':'
  end
  object EditIP: TEdit
    Left = 4
    Top = 17
    Width = 108
    Height = 21
    TabOrder = 0
    Text = '000.000.000.000'
  end
  object EditName: TEdit
    Left = 118
    Top = 17
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'NachOPS3'
  end
  object EditFullName: TEdit
    Left = 4
    Top = 55
    Width = 235
    Height = 21
    TabOrder = 2
    Text = 'WINPOSTZP(192.168.0.236)'
  end
  object BitBtn1: TBitBtn
    Left = 84
    Top = 120
    Width = 75
    Height = 25
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 3
  end
  object BitBtn2: TBitBtn
    Left = 166
    Top = 120
    Width = 75
    Height = 25
    Kind = bkCancel
    NumGlyphs = 2
    TabOrder = 4
  end
end
