object FormEquip: TFormEquip
  Left = 0
  Top = 0
  Caption = 'FormEquip'
  ClientHeight = 293
  ClientWidth = 554
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
  object DBGrid1: TDBGrid
    Left = 0
    Top = 0
    Width = 554
    Height = 293
    Align = alClient
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'fname'
        Width = 250
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'tip'
        Width = 100
        Visible = True
      end>
  end
  object DBNavigator1: TDBNavigator
    Left = 0
    Top = 264
    Width = 240
    Height = 25
    DataSource = DataSource1
    TabOrder = 1
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 180
    Top = 76
  end
  object ADOTable1: TADOTable
    Connection = Form1.ADOConnection1
    CursorLocation = clUseServer
    CursorType = ctStatic
    TableName = 'equip'
    Left = 68
    Top = 140
  end
  object ADOQuery1: TADOQuery
    Connection = Form1.ADOConnection1
    Parameters = <>
    Left = 240
    Top = 140
  end
end
