object rViaForm: TrViaForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'rViaForm'
  ClientHeight = 547
  ClientWidth = 501
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
  object TreeView2: TTreeView
    Left = 241
    Top = 0
    Width = 260
    Height = 524
    Align = alLeft
    BevelInner = bvNone
    BevelOuter = bvNone
    Color = clCream
    DragMode = dmAutomatic
    Images = Form1.ImageList2
    Indent = 35
    TabOrder = 0
    OnClick = TreeView2Click
  end
  object TreeView1: TTreeView
    Left = 0
    Top = 0
    Width = 241
    Height = 524
    Align = alLeft
    BevelInner = bvNone
    BevelOuter = bvNone
    Color = clCream
    DragMode = dmAutomatic
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Images = ImageList1
    Indent = 35
    ParentFont = False
    ParentShowHint = False
    ReadOnly = True
    RightClickSelect = True
    RowSelect = True
    ShowHint = True
    TabOrder = 1
    Touch.ParentTabletOptions = False
    Touch.TabletOptions = [toPressAndHold]
    OnClick = TreeView1Click
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 524
    Width = 501
    Height = 23
    Align = alBottom
    Caption = 'ToolBar1'
    TabOrder = 2
    object BitBtn1: TBitBtn
      Left = 0
      Top = 0
      Width = 80
      Height = 22
      Caption = '&'#1042#1099#1073#1088#1072#1090#1100
      Kind = bkOK
      NumGlyphs = 2
      TabOrder = 0
    end
    object BitBtn2: TBitBtn
      Left = 80
      Top = 0
      Width = 86
      Height = 22
      Align = alRight
      Caption = '&'#1054#1090#1084#1077#1085#1072
      Kind = bkCancel
      NumGlyphs = 2
      TabOrder = 1
    end
  end
  object ADOQuery1: TADOQuery
    Connection = Form1.ADOConnection1
    Parameters = <>
    Left = 301
    Top = 36
  end
  object ImageList1: TImageList
    Left = 64
    Top = 160
    Bitmap = {
      494C010106000800A40010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001A5888001A578700195585001954
      8400185382001853810017527F0017517E0016507D00164F7C00154E7A00154D
      7900154D7800154C7800144C7700144B76000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001B598A007DACE00080AEE4007EAA
      E2007DA7E0007BA5DF0079A1DE00789FDD00769DDC00759ADB007498DA007397
      DA007397DA007397DA007397DA00144C77000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000282828002828
      2800000000002828280028282800000000000000000000000000000000000000
      0000282828002828280000000000000000001B5A8B007FB1E3005093DC004389
      D8004184D5003F7FD4003C7BD1003A76CF003772CD00356FCC00336CCA003168
      C9003066C8002F64C8007397DA00154C78000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000028282800636363006B6B
      6B00282828006E6E6E005B5B5B00282828000000000000000000000000002828
      2800636363005B5B5B0028282800000000001C5B8D0082B6E500549CDF004991
      DB00468CD9004388D7004082D5003E7ED3003B7AD0003975CE003671CD00346D
      CB00326ACA003167C9007497DA00154D79000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000002D0000002C0000002A00000029
      0000002800000027000000270000002600000025000000250000003C0000003B
      0000003A00000039000000380000000000001C5C8E0084BCE60058A3E3004E9A
      DE004B95DC004890DA00468BD8004286D6003F81D4003D7CD1003B79D0003773
      CE003670CC00336DCB00759ADB00154E7A000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000005500004AA54A0042A142003A9D
      3A003198310029942900229122001A8D1A00158A15000F880F00006B0000ABD5
      AB00A7D3A700A4D2A400005C0000000000001D5D900087C0E8005DABE60053A2
      E3004F9DE1004C98DE004A93DC00478EDA004389D8004184D5003F7FD4003C7B
      D1003A76CF003772CD00779EDD00164F7B000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000005D000056AB56001D8E1D001188
      110007840700007E0000007900000074000000700000198C190000700000B2D9
      B2007BBD7B00AAD5AA0000610000000000001D5E91008AC5EA0061B2E90057A9
      E60054A5E40051A1E2004E9BE0004C97DD004991DB00468CD9004388D7004082
      D5003E7ED3003B7AD0007AA2DE0016507D000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000065000062B162002D962D002291
      2200178C17000D860D0002810200007C0000007600002291220000760000BADD
      BA00B6DBB600EEF7EE0000660000000000001E5F93008CC8ED0064B7EB005AB1
      E90058ADE70056A8E50053A4E300509FE2004E9ADE004B95DC004890DA00468B
      D8004286D6003F81D4007DA7E00017517E000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000006D000029942900FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000720000007B0000A9D4
      A900E6F3E600EFF7EF00006B0000000000001E6094008ECCEE008ECCF40086C4
      F20082C2F1007FBEEF007CBBEE0079B7EB0074B3EA0070AFE8006DAAE60068A6
      E50065A2E300619DE1007FACE300175280000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000073000080C08000007100000071
      0000007100000071000000710000007100000071000080C08000007F0000B0D8
      B000ACD6AC0083C1830000700000000000001E61950076B0D900286DA3001660
      9A00165D9800165B9500155A910014588D0014558A001353860013508100124D
      7D00124B790038678B00668DAF00185381000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000079000080C0800055AA55004EA7
      4E0045A245003B9E3B0032993200279427001D8E1D0045A24500078307000181
      0100007D0000007A000000760000000000001F619600407BA9006395BD002A6E
      A5001F67A0001F649E001F639B001E6198001E5F94001D5E90001D5C8E001C58
      89003E6F97005A83A500376A9300185483000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000007F000087C3870083C183007EBF
      7E0077BB770071B871006AB56A0062B1620059AC590052A95200004D00000000
      000000000000000000000000000000000000000000001F6196003E79A7005F92
      BB006093BB006092BB005F91BA005F90B8005F8FB6005F8EB4005E8DB2005E8B
      AF005987AA00376C970019568600000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000006830600007F0000007C00000078
      000000720000006D00000066000000600000005A000000540000005100000000
      00000000000000000000000000000000000000000000000000001F6196001E61
      95001E6095001E6094001E5F93001D5E91001D5D90001C5C8F001C5B8E001B5A
      8C001B5A8B001A59890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000093603D00935F3C00925F
      3B0094613D0094613D0093603C0093603B00925F3A00925F3A00915E3900925E
      3A008F614100593F2A0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000094613E00CCAA8400D1AE
      8800CAA57D00CAA47C00C9A27A00C9A07900C89F7700C89D7600C79C7400C79B
      72008E614000593F2A0000000000000000002271B8002976BA002876BC002676
      BB002676BB002676BB002576BB002576BB002576BB002476BB002476BB002476
      BB002375BB002575BC002776BA002270B8000000000013345200122A3F000A11
      18000A0C0F000A0C0F000A0C0F000A0C0F000A0C0F000A0C0F000A0C0F000A0C
      0F00090B0E000A0F1400112C4500000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000095623F00CAA88400A277
      5300C4986500C3976200C2955F00C1935D00C0905A00BF8D5700BF8B5500D2B0
      89008E614000593F2A000000000000000000307FC1008CC0E4007FC4E8006BBD
      E50066BDE50060BCE5005ABBE50055BBE50050B9E5004BB8E50047B7E40042B6
      E3003DB4E40051BBE60078BFE300277ABF0000000000141C2300DADBDB00A6A6
      A6009E9E9E0098989800919191008B8B8B00848484007F7F7F00797979007474
      740071717100C2C3C30012181C00000000000000000000000000282828002828
      2800000000002828280028282800000000000000000000000000000000000000
      0000282828002828280000000000000000000000000095634000CBAB8700A57D
      5600C79D6C00C69C6900C59A6600C4986300C2956000C1935E00C1915B00D2B0
      8B008F624100593F2A0000000000000000003488C700AEDBF20093E2F80073D9
      F40069D7F4005DD5F30052D3F20047D0F1003CCDF10032CAF10028C9EF0021C4
      EB001CBDE50043C8E80091D8EF002981C30000000000171A1D00F0F0F000ADAD
      AD009F9F9F009191910084848400777777006B6B6B005F5F5F00535353004949
      490041414100D0D0D000171A1D00000000000000000028282800636363006B6B
      6B00282828006E6E6E005B5B5B00282828000000000000000000000000002828
      2800636363005B5B5B0028282800000000000000000096644200CEAF8D00A984
      5A00CAA27300C9A17000C89F6E00C79D6A00C59A6700C4986400C4976200D3B2
      8D008F624100593F2A000000000000000000358CC800B3DCF10097E6F80076DF
      F6006ADCF5005CD9F4004FD6F30041D2F20034D0F20027CBF1001BC9EF0011C5
      EC0008BDE50035C8E70091D9F0002A84C400000000001C1F2100F2F2F200BCBC
      BC00AFAFAF00A2A2A2009494940087878700797979006D6D6D00616161005555
      55004B4B4B00D2D2D2001A1D20000000000085000000820000007E0000007B00
      0000780000007500000073000000700000006E0000006D000000513A29005039
      28004F3727004E3626004D352500000000000000000097654300D0B39100AE8A
      5F00CDA77A00CCA67700CBA47500CAA27100C89F6E00C79D6B00C79C6900D4B3
      8F008F634200593F2A0000000000000000003691C800B6DDF000A4E8F80087E2
      F7007BDFF6006EDCF40060D9F40052D5F20045D3F20038CFF2002CCCF00020CA
      F00012C6ED003BCEEE0093D9F0002A89C4000000000021232500F6F6F600D0D0
      D000C2C2C200B7B7B700A9A9A900999999008C8C8C007F7F7F00737373006767
      67005D5D5D00D6D6D6001F22240000000000FD000000FF777700FF717100FF6B
      6B00FF646400FF5E5E00FF595900FF535300FF4F4F00FF4B4B00A9663100ECD4
      BF00EBD2BC00EAD1B9009B552300000000000000000098664400D2B69500B391
      6400CFAB8000CEAA7E00CDA87B00CCA67800CAA37500C9A17200C9A06F00D5B5
      920090634200593F2A0000000000000000003697C900B7E3F200B6EEFA00A0E9
      FA0096E6F9008CE3F8007FE0F6006FDCF30059D8F3004BD4F3003DD0F30031CE
      F10022CAF00045D3F30096DBF100298EC5000000000025272800FEFEFE00F9F9
      F900F8F8F800F6F6F600F4F4F400DDDDDD00A2A2A20095959500888888007B7B
      7B0071717100DBDBDB002226270000000000FF0B0B00FF808000FF555500FF4C
      4C00FF454500FF3D3D00FF353500FF2D2D00FF272700FF525200AE6C3500EDD8
      C400E1BB9A00EBD4BE009F5A2700000000000000000098674500D5BA9A00B799
      6800D4B28900D2AE8600D0AC8100CFA97C00CDA57700CBA37300CCA37400D5B6
      940090634200593F2A000000000000000000369BC800BAECF500CCF3FD00C4EE
      FD00C1EDFD00C2ECFB00C1EFF900A9EAF70076DEF60064DAF50058D8F4004CD4
      F2003ED0F1005BD8F3009DDCF1002A92C5000000000027292A00E7E7E7009090
      90008383830069696900C6C6C600F4F4F400F4F4F400F4F4F400F2F2F200F1F1
      F100F0F0F000FEFEFE00272B2C0000000000FF171700FF898900FF616100FF59
      5900FF515100FF494900FF414100FF393900FF313100FF595900B3723A00EFDC
      CA00EEDAC800FFF6EF00A4602C00000000000000000099684600D7BE9E00BC9E
      6E00D4B48F00CBAC8700C7A78000C5A47C00C3A07900C4A07500CBA67A00D6B7
      960090644300593F2A000000000000000000349CC700AFDEEE0094D6F00077C9
      EC006AC0E9007AC4E900B3E3F300C7F1F900BEEFFA00BAEEFA00B7EEF900B4ED
      F900B0EAF900B9F1FB00B6EBF5002C97C50000000000272D3000F1F1F1009A9A
      9A0098989800868686006C6C6C006C6C6C0085858500818181007C7C7C007878
      780075757500E8E8E800282E300000000000FF232300FF5E5E00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF2B2B00B8783F00EED3
      BB00FFF2E700FFF6F000A966310000000000000000009A694700D9C1A300C0A3
      7100D2B79300F5EDE400F4ECE200F4ECE100F4EBE000F3EADF00CBA87E00D7B9
      980090644400593F2A000000000000000000359CC700B1DDEE0087D6F10067C9
      ED005DC4EB0056BFE90062C6EA006FCDEB007FD2EE007ED2EF007AD1EE0077D0
      EF0072CFEE008CDAF100B2E3EF002B9AC3000000000029303300F7F7F7009C9C
      9C0098989800A3A3A300ADADAD00F1F1F100F6F6F600F4F4F400F3F3F300F1F1
      F100F0F0F000FAFAFA002B3D440000000000FF2C2C00FFA0A000FF292900FF29
      2900FF292900FF292900FF292900FF292900FF292900FFA0A000BC7D4300EFD7
      C100EED5BE00E2BFA200AE6C350000000000000000009A694800DBC4A500C5A6
      7500D9BE9A00D1B69200CBAF8D00CAAD8900C8AA8600CBAA8200D1AF8600D7B9
      990090634300593F2A000000000000000000369EC800B6E0F00084DDF50064D2
      F10068D0EF0063CAEE0065C8EC0083D5EF0095DDF20095DCF20091DBF2008DDA
      F20088D9F2009DE0F500B5E0F200279BC500000000002D303100FCFCFC00FEFE
      FE00FEFEFE00FDFDFD00FEFEFE00E9E9E9006567670064666700646667006466
      6700737576006D7679000000000000000000FF353500FFA0A000FF7F7F00FF7A
      7A00FF737300FF6C6C00FF656500FF5D5D00FF555500FF737300C0824600BD7F
      4400BA7B4100B7773E00B3723A0000000000000000009B6A4900DDC8A800D4BC
      9400E6D4B800E6D1B500E4D0B400E3CEB200E2CBAF00E0C9AC00DFC7A800DABE
      9F008F604000593F2A00000000000000000037A2C700C0E2EE00A4EBF9008BDB
      F70094D6F6009DDEF600ADE6F700CAEFF900A8E5F400A2E2F200A2E2F200A0E1
      F200A1E1F300A6E3F50099D4ED0054A1BE00000000002C40460056585800595B
      5B00595B5B00595B5B00585A5A00334246000000000000000000000000000000
      000000000000000000000000000000000000FF3E3E00FFA5A500FFA2A200FF9E
      9E00FF999900FF949400FF8F8F00FF898900FF828200FF7D7D00E60000000000
      000000000000000000000000000000000000000000009B6B4A00D9C1A400B490
      6F00AA7F5E00A87D5D00A87D5D00A77C5B00A77B5A00A67A5900A57858009B6A
      48008E5E3D00593F2A00000000000000000034A3C600ACDAE500BFF0F500BADC
      F800BAD5F800B9E6F800B7EEF600A3DAEA005FBAD70057B6D30058B7D30057B6
      D3005CB8D40061BBD6006AB7CF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF444400FF3E3E00FF393900FF33
      3300FF2B2B00FF232300FF191900FF101000FF070700FB000000F20000000000
      000000000000000000000000000000000000000000009C6C4A00B9967700D8C4
      B800E8DED700E7DDD600E6DCD600E4DBD400E3DAD300E2D8D100E1D7D000EBE7
      E500EFEFEF00563D29000000000000000000279EC20046B5D8004DBCDF004CBA
      DF004CB9DF004CBBDF0046B9DC0041AAC90096ADB300A1ADB000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000009C6C4B009C6C4A00BA96
      7700AB816100AB806000AA7F5F00AA7E5E00A97E5D00A77D5C00A77B5B009C6C
      4B0096654200875B3B0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000009C6C4B009C6C
      4A009C6B4A009B6B49009B6A48009A6948009A69470099684600986745009766
      440092634200835C3D0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFF00000000FFFF000000000000
      FFFF000000000000C9F300000000000080E10000000000000001000000000000
      0001000000000000000100000000000000010000000000000001000000000000
      00010000000000000001000000000000001F800100000000001FC00300000000
      FFFFFFFF00000000FFFFFFFF00000000FFFFFFFF8003FFFFFFFFFFFF80030000
      8001FFFF800300008001C9F380030000800180E1800300008001000180030000
      8001000180030000800100018003000080010001800300008001000180030000
      8001000180030000800300018003000080FF001F80030001FFFF001F8003003F
      FFFFFFFF8003FFFFFFFFFFFFC003FFFF00000000000000000000000000000000
      000000000000}
  end
end