object Server: TServer
  Left = 0
  Top = 0
  Caption = 'UDP Server'
  ClientHeight = 700
  ClientWidth = 800
  Color = clBtnFace
  Constraints.MinHeight = 700
  Constraints.MinWidth = 800
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Memo1: TMemo
    Left = 0
    Top = 55
    Width = 800
    Height = 615
    Align = alClient
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 0
    ExplicitLeft = 3
    ExplicitTop = 52
    ExplicitWidth = 794
    ExplicitHeight = 609
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 670
    Width = 800
    Height = 30
    Panels = <>
    SimplePanel = True
    SimpleText = 'simple text'
    ExplicitTop = 618
    ExplicitWidth = 751
  end
  object Controls: TGroupBox
    Left = 0
    Top = 0
    Width = 800
    Height = 55
    Align = alTop
    Caption = 'Controls'
    TabOrder = 2
    ExplicitWidth = 832
    ExplicitHeight = 49
    object Enable: TCheckBox
      Left = 16
      Top = 23
      Width = 97
      Height = 17
      Caption = 'Enable'
      TabOrder = 0
      OnClick = EnableClick
    end
    object IPs: TEdit
      Left = 217
      Top = 20
      Width = 120
      Height = 23
      TabOrder = 1
      TextHint = 'Address'
      OnChange = IPsChange
    end
    object DefaultPort: TEdit
      Left = 409
      Top = 20
      Width = 120
      Height = 23
      TabOrder = 2
      TextHint = 'Default Port'
      OnChange = DefaultPortChange
    end
    object BufferSize: TEdit
      Left = 641
      Top = 20
      Width = 120
      Height = 23
      TabOrder = 3
      TextHint = 'BufferSize'
      OnChange = BufferSizeChange
    end
  end
  object IdUDPServer1: TIdUDPServer
    Bindings = <>
    DefaultPort = 0
    Left = 256
    Top = 384
  end
end
