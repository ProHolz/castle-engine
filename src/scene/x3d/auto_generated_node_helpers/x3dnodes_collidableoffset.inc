{ -*- buffer-read-only: t -*-

  Copyright 2015-2023 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Automatically generated node properties.

  Do not edit this file manually!
  To add new properties:
  - add them to the text files in tools/internal/x3d-nodes-to-pascal/nodes-specification/ ,
  - and regenerate include files by running x3d-nodes-to-pascal }

{$ifdef read_interface}

  strict private
    function GetCollidable: TAbstractNBodyCollidableNode;
    procedure SetCollidable(const Value: TAbstractNBodyCollidableNode);
  public
    procedure CreateNode; override;
    class function ClassX3DType: string; override;

    strict private FFdCollidable: TSFNode;
    { Internal wrapper for property @link(Collidable). This wrapper API may change, we advise to access simpler @link(Collidable) instead. }
    public property FdCollidable: TSFNode read FFdCollidable;
    {  }
    property Collidable: TAbstractNBodyCollidableNode read GetCollidable write SetCollidable;

{$endif read_interface}

{$ifdef read_implementation}

{ TCollidableOffsetNode ----------------------------------------------- }

function TCollidableOffsetNode.GetCollidable: TAbstractNBodyCollidableNode;
begin
  if FdCollidable.Value is TAbstractNBodyCollidableNode then
    Result := TAbstractNBodyCollidableNode(FdCollidable.Value)
  else
    Result := nil;
end;

procedure TCollidableOffsetNode.SetCollidable(const Value: TAbstractNBodyCollidableNode);
begin
  FdCollidable.Send(Value);
end;

class function TCollidableOffsetNode.ClassX3DType: String;
begin
  Result := 'CollidableOffset';
end;

procedure TCollidableOffsetNode.CreateNode;
begin
  inherited;

  FFdCollidable := TSFNode.Create(Self, False, 'collidable', [TAbstractNBodyCollidableNode]);
   FdCollidable.ChangeAlways := chVisibleNonGeometry;
  AddField(FFdCollidable);
end;

{$endif read_implementation}
