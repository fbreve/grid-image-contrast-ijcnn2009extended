object frmLogPixels: TfrmLogPixels
  Left = 0
  Top = 0
  Caption = 'Select the oscilators to be logged...'
  ClientHeight = 600
  ClientWidth = 830
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ImageLogPixels: TImage
    Left = 131
    Top = 0
    Width = 699
    Height = 600
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Align = alRight
    Picture.Data = {
      07544269746D6170A2000000424DA2000000000000003E000000280000001900
      000019000000010001000000000064000000232E0000232E0000020000000000
      000000000000FFFFFF0000000000000FFC00000FFC00000FFC00000FFC00000F
      FC00000FFC00000FFC0000000000000000000000000000000000FFFC00007FF8
      3C003FF07E001FE0FF000FC0FF000780FF000300FF000000FF0000007E000000
      3C00000000000000000000000000}
    Stretch = True
    OnMouseDown = ImageLogPixelsMouseDown
    OnMouseMove = ImageLogPixelsMouseMove
    ExplicitLeft = 98
    ExplicitTop = -5
  end
  object Label1: TLabel
    Left = 5
    Top = 8
    Width = 42
    Height = 19
    Caption = 'Class:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 532
    Width = 63
    Height = 13
    Caption = 'Selected Pts:'
  end
  object LabelSelectedPoints: TLabel
    Left = 82
    Top = 532
    Width = 31
    Height = 13
    Alignment = taRightJustify
    Caption = '0'
  end
  object UpDownClass: TUpDown
    Left = 92
    Top = 32
    Width = 15
    Height = 31
    Associate = EditClass
    TabOrder = 1
  end
  object EditClass: TEdit
    Left = 5
    Top = 32
    Width = 87
    Height = 31
    BiDiMode = bdRightToLeft
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
    TabOrder = 0
    Text = '0'
  end
  object StringGrid1: TStringGrid
    Left = 5
    Top = 69
    Width = 108
    Height = 457
    ColCount = 4
    DefaultColWidth = 20
    DefaultRowHeight = 10
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -7
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    ParentFont = False
    TabOrder = 2
  end
  object btnLimparTodos: TButton
    Left = 8
    Top = 580
    Width = 105
    Height = 19
    Caption = 'Limpar &Tudo'
    TabOrder = 3
    OnClick = btnLimparTodosClick
  end
  object btnLimparUltimo: TButton
    Left = 8
    Top = 551
    Width = 105
    Height = 23
    Caption = 'Limpar &'#218'ltimo'
    TabOrder = 4
    OnClick = btnLimparUltimoClick
  end
end
