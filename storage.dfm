object FormStorage: TFormStorage
  Left = 0
  Top = 0
  Caption = #1057#1082#1083#1072#1076
  ClientHeight = 334
  ClientWidth = 786
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object SpeedButton1: TSpeedButton
    Left = 759
    Top = 4
    Width = 23
    Height = 22
    OnClick = SpeedButton1Click
  end
  object SpeedButton2: TSpeedButton
    Left = 759
    Top = 28
    Width = 23
    Height = 22
    OnClick = SpeedButton2Click
  end
  object SpeedButton3: TSpeedButton
    Left = 759
    Top = 64
    Width = 23
    Height = 22
    OnClick = SpeedButton3Click
  end
  object StringGrid1: TStringGrid
    Left = 4
    Top = 3
    Width = 754
    Height = 297
    ColCount = 8
    DefaultRowHeight = 18
    RowCount = 2
    Options = [goFixedHorzLine, goHorzLine, goRowSelect, goFixedColClick, goFixedRowClick]
    TabOrder = 0
    OnDrawCell = StringGrid1DrawCell
    OnFixedCellClick = StringGrid1FixedCellClick
  end
  object BitBtn1: TBitBtn
    Left = 683
    Top = 306
    Width = 75
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    TabOrder = 1
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 336
    Top = 306
    Width = 75
    Height = 25
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 2
    OnClick = BitBtn2Click
  end
  object ADOQuery1: TADOQuery
    AutoCalcFields = False
    Connection = Form1.ADOConnection1
    Parameters = <>
    Left = 36
    Top = 200
  end
  object ADOQuery2: TADOQuery
    AutoCalcFields = False
    Connection = Form1.ADOConnection1
    Parameters = <>
    Left = 108
    Top = 204
  end
end
