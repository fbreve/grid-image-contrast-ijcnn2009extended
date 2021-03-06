//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef logpixelsH
#define logpixelsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmLogPixels : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageLogPixels;
	TUpDown *UpDownClass;
	TEdit *EditClass;
	TLabel *Label1;
	TStringGrid *StringGrid1;
	TButton *btnLimparTodos;
	TButton *btnLimparUltimo;
	TLabel *Label2;
	TLabel *LabelSelectedPoints;
	void __fastcall markPixel(int X, int Y);
	void __fastcall ImageLogPixelsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall btnLimparUltimoClick(TObject *Sender);
	void __fastcall btnLimparTodosClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ImageLogPixelsMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmLogPixels(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLogPixels *frmLogPixels;
//---------------------------------------------------------------------------
#endif
