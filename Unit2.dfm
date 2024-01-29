object Server: TServer
  Left = 0
  Top = 0
  Caption = 'Server'
  ClientHeight = 648
  ClientWidth = 751
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  DesignSize = (
    751
    648)
  TextHeight = 15
  object Enable: TCheckBox
    Left = 0
    Top = 8
    Width = 97
    Height = 17
    Caption = 'Enable'
    TabOrder = 0
    OnClick = EnableClick
  end
  object Memo1: TMemo
    Left = 0
    Top = 37
    Width = 751
    Height = 580
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
    ExplicitWidth = 767
    ExplicitHeight = 370
  end
  object IPs: TEdit
    Left = 152
    Top = 8
    Width = 120
    Height = 23
    TabOrder = 2
    TextHint = 'Address'
    OnChange = IPsChange
  end
  object DefaultPort: TEdit
    Left = 278
    Top = 8
    Width = 120
    Height = 23
    TabOrder = 3
    TextHint = 'Default Port'
    OnChange = DefaultPortChange
  end
  object BufferSize: TEdit
    Left = 404
    Top = 8
    Width = 120
    Height = 23
    TabOrder = 4
    TextHint = 'BufferSize'
    OnChange = BufferSizeChange
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 618
    Width = 751
    Height = 30
    Panels = <>
    SimplePanel = True
    SimpleText = 'simple text'
    ExplicitTop = 408
    ExplicitWidth = 767
  end
  object IdUDPServer1: TIdUDPServer
    Bindings = <>
    DefaultPort = 0
    Left = 256
    Top = 384
  end
end
